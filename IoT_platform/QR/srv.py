# -*- coding: utf-8 -*-
import qrcode
import random
import requests
from twilio.rest import Client

r = [101, 102, 103]
r2 = []
get_check_path = False
get_origin_path = False
gen_qrcode_path = False

def post_key(num):
    url = "http://180.83.19.43:7579/Mobius/test/key"
    headers =	{
                    'Accept':'application/json',
                    'X-M2M-RI':'12345',
                    'X-M2M-Origin':'XXXXXXXXXXX', # change to your aei
                    'Content-Type':'application/vnd.onem2m-res+json; ty=4'
                }

    data =	{
                "m2m:cin": {
                    "con": str(num)
                }
            }

    r = requests.post(url, headers=headers, json=data)

    try:
        r.raise_for_status()
        print("key값이 잘 전송되었습니다. " + str(num))
    except Exception as exc:
        print('There was a problem: %s' % (exc))

# 값 체크
def get_check(num):
    global cin_rn
    url = url = "http://180.83.19.43:7579/Mobius/test/" + str(num) + "/user/check" + "?fu=2&la=3&ty=4&rcn=4"

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
        print(str(num) + "호는 Check 값이 없습니다.")
        return False


def get_origin(num):
    global origin_data
    url = "http://180.83.19.43:7579/Mobius/test/" + str(num) + "/user/origin_data" + "?fu=2&la=3&ty=4&rcn=4"

    headers = {'Accept':'application/json',
                'X-M2M-RI':'12345',
                'X-M2M-Origin':'SOrigin'}

    r = requests.get(url, headers=headers)

    try:
        r.raise_for_status()
        jr = r.json()

        # c['rn']을 추가함으로써 delete를 위한 resource name get
        for c in jr['m2m:rsp']['m2m:cin']:
            print(str(num) + "호 " + "origin_data 값:", c['con'])
            origin_data = c['con']
            return True
    except Exception as exc:
        print(str(num) + "호의 Origin Number가 존재하지 않거나 이상이 있습니다.")
        return False


def del_check(num, cin_rn):
    url = "http://180.83.19.43:7579/Mobius/test/" + str(num) + "/user/check/" + str(cin_rn)

    payload = ""
    headers = {
    'Accept': 'application/xml',
    'X-M2M-RI': '12345',
    'X-M2M-Origin': 'SIWLTfduOpL'
    }

    response = requests.request("DELETE", url, headers=headers, data=payload)

    print(str(num) + "호의 Check 값이 삭제되었습니다.")

# def post_bindind_data(num, origin_data):
#     url = 'http://203.253.128.161:7579/Mobius/sch20181536_3/key'
#     headers =	{
#                     'Accept':'application/json',
#                     'X-M2M-RI':'12345',
#                     'X-M2M-Origin':'XXXXXXXXXXX', # change to your aei
#                     'Content-Type':'application/vnd.onem2m-res+json; ty=4'
#                 }

#     data =	{
#                 "m2m:cin": {
#                     "con": "4"
#                 }
#             }

#     r = requests.post(url, headers=headers, json=data)

if __name__ == "__main__":
    key = random.randrange(-99, 99)
    post_key(key)
    cin_rn = 0; origin_data = 0
    while True:
        #     if get_check_path == False:
        #         for i in r:
        #             if
        print()
        for i in r:
            if get_check(i):
                r2.append(i)
                print(cin_rn)
                del_check(i, cin_rn)
                for j in r2:
                    if get_origin(j):
                        print(origin_data)

                        # creating the variable for the QR code
                        qr = qrcode.QRCode(
                            version = 1,
                            box_size = 15,
                            border = 10
                            )

                        # adding a link for the QR code to open
                        # data = random.randrange(1, 9999)
                        qr.add_data(int(origin_data) * int(key))
                        print(str(j) + "의 암호화 값은" + str(int(origin_data) * int(key)) + "입니다.")
                        qr.make(fit=True)

                        # adding the color
                        img = qr.make_image(fill = 'black', back_color = 'white')
                        img.save(str(j) + "qr_code.png")

                        # # Your Account SID from twilio.com/console
                        # account_sid = "ACa933b9922333cbf1cd6f1088d064bec2"
                        # # Your Auth Token from twilio.com/console
                        # auth_token  = "a80f0299951273ef238ff2680b365d82"

                        # client = Client(account_sid, auth_token)

                        # message = client.messages.create(
                        #     to="+821024875498", 
                        #     from_="+19404129266",
                        #     body=("./" + str(j) + "qr_code.png"))

                        # print(message.sid)
                    print()
                    del r2[r2.index(j)]
    
    print()
            
            

            # key 보내기

            # creating the variable for the QR code
            # qr = qrcode.QRCode(
            #     version = 1,
            #     box_size = 15,
            #     border = 10
            #     )

            # # adding a link for the QR code to open
            # # data = random.randrange(1, 9999)
            # qr.add_data(cipher_text)
            # qr.make(fit=True)

            # # adding the color
            # img = qr.make_image(fill = 'black', back_color = 'white')
            # img.save('qrcodewithlink21.png')