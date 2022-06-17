import pyzbar.pyzbar as pyzbar
import cv2
import requests
import time

r = [101, 102, 103]
r2 = [1, 2, 3]
def get_key():
    global key
    url = "http://180.83.19.43:7579/Mobius/test/key?fu=2&la=3&ty=4&rcn=4"

    headers = {'Accept':'application/json',
                'X-M2M-RI':'12345',
                'X-M2M-Origin':'SOrigin'}

    r = requests.get(url, headers=headers)

    try:
        r.raise_for_status()
        jr = r.json()

        # c['rn']을 추가함으로써 delete를 위한 resource name get
        for c in jr['m2m:rsp']['m2m:cin']:
            key = c['con']
            print("Get key!: " + str(key))
            return True
    except Exception as exc:
        return False
        
def get_origin_data(num):
    global cin_origin_data_rn
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
            cin_origin_data_rn = c['rn']
            # print(str(num) + "호 " + "origin_data 값:", c['con'])
            return c['con']
    except Exception as exc:
        return False

def get_box_number(num):
    global cin_num_rn
    url = "http://180.83.19.43:7579/Mobius/test/box" + str(num) + "/num?fu=2&la=3&ty=4&rcn=4"

    headers = {'Accept':'application/json',
                'X-M2M-RI':'12345',
                'X-M2M-Origin':'SOrigin'}

    r = requests.get(url, headers=headers)

    try:
        r.raise_for_status()
        jr = r.json()

        # c['rn']을 추가함으로써 delete를 위한 resource name get
        for c in jr['m2m:rsp']['m2m:cin']:
            cin_num_rn = c['rn']
            return c['con']
    except Exception as exc:
        return False

def post_servo(num):
    url = "http://180.83.19.43:7579/Mobius/test/box" + str(num) + "/servo"
    headers =	{
                    'Accept':'application/json',
                    'X-M2M-RI':'12345',
                    'X-M2M-Origin':'SIWLTfduOpL', # change to your aei
                    'Content-Type':'application/vnd.onem2m-res+json; ty=4'
                }

    data =	{
                "m2m:cin": {
                    "con": "0"
                }
            }

    r = requests.post(url, headers=headers, json=data)

    try:
        r.raise_for_status()
        print("servo value is sended")
    except Exception as exc:
        print('There was a problem: %s' % (exc))

def get_servo(num):
    global cin_servo_rn
    url = "http://180.83.19.43:7579/Mobius/test/box" + str(num) + "/servo?fu=2&la=3&ty=4&rcn=4"

    headers = {'Accept':'application/json',
                'X-M2M-RI':'12345',
                'X-M2M-Origin':'SOrigin'}

    r = requests.get(url, headers=headers)

    try:
        r.raise_for_status()
        jr = r.json()

        # c['rn']을 추가함으로써 delete를 위한 resource name get
        for c in jr['m2m:rsp']['m2m:cin']:
            cin_servo_rn = c['rn']
            return True
    except Exception as exc:
        return False

def del_servo(num, cin_servo_rn):
    url = "http://180.83.19.43:7579/Mobius/test/box" + str(num) + "/servo/" + str(cin_servo_rn)

    payload = ""
    headers = {
    'Accept': 'application/xml',
    'X-M2M-RI': '12345',
    'X-M2M-Origin': 'SIWLTfduOpL'
    }

    response = requests.request("DELETE", url, headers=headers, data=payload)

    print(str(num) + " servo value is delete!")

def del_origin_data(num, cin_origin_data_rn):
    url = "http://180.83.19.43:7579/Mobius/test/" + str(num) + "/user/origin_data/" + str(cin_origin_data_rn)

    payload = ""
    headers = {
    'Accept': 'application/xml',
    'X-M2M-RI': '12345',
    'X-M2M-Origin': 'SIWLTfduOpL'
    }

    response = requests.request("DELETE", url, headers=headers, data=payload)

    print(str(num) + " origin_data is delete!")

def del_num(num, cin_num_rn):
    url = "http://180.83.19.43:7579/Mobius/test/box" + str(num) + "/num/" + str(cin_num_rn)

    payload = ""
    headers = {
    'Accept': 'application/xml',
    'X-M2M-RI': '12345',
    'X-M2M-Origin': 'SIWLTfduOpL'
    }

    response = requests.request("DELETE", url, headers=headers, data=payload)

    print(str(num) + " num is delete!")

cin_servo_rn = 0; cin_origin_data_rn = 0; cin_num_rn = 0
key = 0
get_key()
cap = cv2.VideoCapture('/dev/video0')

i = 0
while(cap.isOpened()):
    ret, img = cap.read() #계속 캡쳐 시작

    if not ret:
        continue

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
    decoded = pyzbar.decode(gray)

    for d in decoded: 
        x, y, w, h = d.rect

        barcode_data = d.data.decode("utf-8")
        barcode_type = d.type

        cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 2)
        # print(int(barcode_data) // int(key))
        # print("new data:", end=' ')
        # print(int(new_data))
        # print(barcode_data)
        # print(new_data)
        text = '%s (%s)' % (barcode_data, barcode_type)
        cv2.putText(img, text, (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2, cv2.LINE_AA)
        # print(str(int(barcode_data) // int(key)))
        for i in r:
            if get_origin_data(i) == str(int(barcode_data) // int(key)):
                print("Data Matched : " + str(i) + "!!!!!!!!!!!!!!!!!!!!!!!")
                for f in r2:
                    if get_box_number(f) == str(i):
                        print("And " + str(i) + " is in Box" + str(f))
                        del_num(f, cin_num_rn)
                        time.sleep(1)
                        # get_servo(f)
                        time.sleep(1)
                        # del_servo(f, cin_servo_rn)
                        time.sleep(1)
                        post_servo(f)
                        time.sleep(1)
                        del_origin_data(i, cin_origin_data_rn)
                        time.sleep(1)
                
                # exit(0)
    cv2.imshow('img', img)
    ke= cv2.waitKey(1)
    if ke == ord('q'): #q키를 누르면 이미지 창이 꺼진다
        break
    elif ke == ord('s'): #s키를 누르면 캡쳐된다.
        i += 1
        cv2.imwrite('c_%03d.jpg' % i, img)
