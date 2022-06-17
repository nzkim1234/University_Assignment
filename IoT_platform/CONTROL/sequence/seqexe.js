const path = './sequence/'
const cp = require('child_process').spawn;
cp('python3', [path + 'ledRedOn.py', '0']);

exports.exe = function exe(cnt, con) {
    cnt_box = cnt.split('/')[2];
    cnt = cnt.split('/')[3];
    // console.log('cnt : ' + cnt);
    // console.log('con : ' + con);

    if(cnt == 'num'){
        if(con == '101'){
            cp('python3', [path + 'ledRedOn.py', 'on2']);
        }
        else if(con == '102'){
            cp('python3', [path + 'ledRedOn.py', 'on4']);
        }
        else if(con = '103'){
            cp('python3', [path + 'ledRedOn.py', 'on1']);
        }
        else;
    }
    else if(cnt == 'servo'){
        if(cnt_box == 'box1' && con == '0'){
            cp('python3', [path + 'ledRedOn.py', 'off2']);
        }
        else if(cnt_box == 'box2' && con == '0'){
            cp('python3', [path + 'ledRedOn.py', 'off4']);
        }
        else if(cnt_box == 'box3' && con == '0'){
            cp('python3', [path + 'ledRedOn.py', 'off1']);
        }
        else;
    }
    else;
}