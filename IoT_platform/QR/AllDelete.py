import requests

r = [101, 102, 103]

def get_origin(num):
    global cin_rn
    url = url = "http://180.83.19.43:7579/Mobius/test/" + str(num) + "/user/origin_data" + "?fu=2&la=3&ty=4&rcn=4"

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

def del_origin(num, cin_rn):
    url = "http://180.83.19.43:7579/Mobius/test/" + str(num) + "/user/origin_data/" + str(cin_rn)

    payload = ""
    headers = {
    'Accept': 'application/xml',
    'X-M2M-RI': '12345',
    'X-M2M-Origin': 'SIWLTfduOpL'
    }

    response = requests.request("DELETE", url, headers=headers, data=payload)

    print(str(num) + "호의 Check 값이 삭제되었습니다.")

if __name__ == "__main__":
    cin_rn = 0

    while True:
        for i in r:
            if get_origin(i) == True:
                del_origin(i, cin_rn)


                
