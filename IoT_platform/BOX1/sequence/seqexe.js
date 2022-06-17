const path = './sequence/'
const cp = require('child_process').spawn;

exports.exe = function exe(cnt, con) {
    cnt = cnt.split('/')[2];
    console.log(cnt);
    console.log(con);
	if ( cnt == 'button_BOX1') {
	    if (con == 'BOX1') {
    	    cp('python3', [path + 'Text_Extraction.py']);
       		console.log('run Text_EX');
		}
    }
	else if (cnt == 'box1') {
		if (con == '0') {
			cp('python3', [path + 'OpenServo.py']);
			console.log('run SO');
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
