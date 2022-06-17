# -*- coding: utf-8 -*-
import qrcode
import random
import requests
from twilio.rest import Client

r = [101, 102, 103]
# pr = ["+821077606799", "+821024875498", "+821036997615", "+821055392979"]
# pr = ["+821077606799", "+821024875498", "+821036997615"]
r2 = []
get_check_path = False
get_origin_path = False
gen_qrcode_path = False

def get_check(num):
    global cin_rn
    url = url = "http://192.168.219.114:7579/Mobius/test/" + str(num) + "/user/check" + "?fu=2&la=3&ty=4&rcn=4"

    headers = {'Accept':'application/json',
                'X-M2M-RI':'12345',
                'X-M2M-Origin':'SOrigin'}

    r = requests.get(url, headers=headers)

    try:
        r.raise_for_status()
        jr = r.json()
        # c['rn']을 추가함으로써 delete를 위한 resource name get
        for c in jr['m2m:rsp']['m2m:cin']:
            print(str(num) + "호 " + "Check 값:", c['con'], c['rn'])
            cin_rn = c['rn']
            return True
    except Exception as exc:
        return False


def get_origin(num):
    global origin_data
    url = "http://192.168.219.114:7579/Mobius/test/" + str(num) + "/user/origin_data" + "?fu=2&la=3&ty=4&rcn=4"

    headers = {'Accept':'application/json',
                'X-M2M-RI':'12345',
                'X-M2M-Origin':'SOrigin'}

    r = requests.get(url, headers=headers)

    try:
        r.raise_for_status()
        jr = r.json()

        for c in jr['m2m:rsp']['m2m:cin']:
            print(str(num) + "호 " + "origin_data 값:", c['con'])
            origin_data = c['con']
            return True
    except Exception as exc:
        print(str(num) + "호의 Origin Number가 존재하지 않거나 이상이 있습니다.")
        return False

def get_phone(num):
    global phone_data
    url = url = "http://192.168.219.114:7579/Mobius/test/" + str(num) + "/user/phone" + "?fu=2&la=3&ty=4&rcn=4"

    headers = {'Accept':'application/json',
                'X-M2M-RI':'12345',
                'X-M2M-Origin':'SOrigin'}

    r = requests.get(url, headers=headers)

    try:
        r.raise_for_status()
        jr = r.json()
        # c['rn']을 추가함으로써 delete를 위한 resource name get
        for c in jr['m2m:rsp']['m2m:cin']:
            print(str(num) + "호 " + "Check 값:", c['con'])
            phone_data = c['con']
            return True
    except Exception as exc:
        print("none")
        return False


def del_check(num, cin_rn):
    url = "http://192.168.219.114:7579/Mobius/test/" + str(num) + "/user/check/" + str(cin_rn)

    payload = ""
    headers = {
    'Accept': 'application/xml',
    'X-M2M-RI': '12345',
    'X-M2M-Origin': 'SIWLTfduOpL'
    }

    response = requests.request("DELETE", url, headers=headers, data=payload)

    print(str(num) + "호의 Check 값이 삭제되었습니다.")

if __name__ == "__main__":
    cin_rn = 0; origin_data = 0; phone_data = 0
    k = 0
    while True:
        for i in r:
            if get_check(i):
                r2.append(i)
                print(cin_rn)
                del_check(i, cin_rn)
                for j in r2:
                    if get_origin(j):
                        print(origin_data)
                        qr = qrcode.QRCode(
                            version = 1,
                            box_size = 15,
                            border = 10
                            )
                        get_phone(j)
                        qr.add_data(int(origin_data) * int(34))
                        print(str(j) + "의 암호화 값은" + str(int(origin_data) * int(34)) + "입니다.")
                        qr.make(fit=True)

                        img = qr.make_image(fill = 'black', back_color = 'white')
                        img.save("/var/www/html/" + str(j) + "qr_code.png")
                        # print(pr[k])

                        account_sid = "ACa933b9922333cbf1cd6f1088d064bec2"
                        auth_token  = "a80f0299951273ef238ff2680b365d82"

                        client = Client(account_sid, auth_token)
                        message = client.messages.create(
                            to=str(phone_data),
                            from_="+19404129266",
                            body=("http://180.83.19.43:8001/"+ str(j) + "qr_code.png"))
                            
                    # if k > 2: k = 0
                    # else: k += 1
                    print()
                    del r2[r2.index(j)]