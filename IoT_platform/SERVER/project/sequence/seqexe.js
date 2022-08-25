const path = './sequence/'
const cp = require('child_process');
exports.exe = function exe(cnt, con) {
    cnt = cnt.split('/')[2];
    console.log(cnt);
    console.log(con);
    if (cnt == '101') {
        if (con == '1') {
            cp.exec('sudo python3 ./sequence/qr_generater.py');
            console.log('run mkqr');
        }
    }
    else if (cnt == '102') {
        if (con == '1') {
            cp.exec('sudo python3 ./sequence/qr_generater.py');
            console.log('run mkqr');
        }
    }
    else if (cnt == '103') {
        if (con == '1') {
            cp.exec('sudo python3 ./sequence/qr_generater.py');
            console.log('run mkqr');
        }
    }
    else {
        ;
    }
}


// const cp = require('child_process').spawn;
// cp('python3', ['Text_Extraction.py']);

// switch (process.argv[2]) {
//     case '11':
//         console.log('run EX');
//         // const cp = require('child_process').spawn;
//         cp('python3', [path + 'Text_Extraction.py']);
//         break;
//     default:
//     // console.log('Sorry, wrong command!');
// }
