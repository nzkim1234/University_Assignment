const path = './sequence/'
console.log('run EX');
const cp = require('child_process').spawn;
cp('python3', ['Text_Extraction.py']);

switch (process.argv[2]) {
    case '11':
        console.log('run EX');
        const cp = require('child_process').spawn;
        cp('python3', ['Text_Extraction.py']);
        break;
    default:
    // console.log('Sorry, wrong command!');
}

exports.exe = function exe(cnt, con) {
    // cnt = cnt.split('/')[2];
    // console.log(cnt);
    // console.log(con);
    // const cp = require('child_process').spawn;
    // cp('python3', [path + 'Text_Extraction.py']);
    // console.log('run Text_EX');

    // if (con == '11') {
    //     const cp = require('child_process').spawn;
    //     cp('python3', [path + 'Text_Extraction.py']);
    //     console.log('run Text_EX');
    // }
    // else {
    //     ;
    // }
}