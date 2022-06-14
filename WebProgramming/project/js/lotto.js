let lotto_num_sub_id, lotto_btn_id;
      let lottoArr, index, delay;
    
      init();
    
      function init(){
          lotto_num_sub_id = document.getElementById("lotto_num_sub_id");
          lotto_btn_id = document.getElementById("lotto_btn_id");
      }
    
      function lottoFunc(){
          lottoArr = new Array();
          lotto_num_sub_id.innerHTML = "";
          index = 0;
          delay = 0;
    
          runLottoSys();
      }
    
      function runLottoSys(){
          for(let i=0; i<7; i++){
              let lotto = Math.floor(Math.random() * 45) + 1;
    
              // 중복 검사
              while(true){
                  if(lottoArr.indexOf(lotto) < 0) {
                      lottoArr[index] = lotto;
                      index++;
                      break;
                  } else {
                      lotto = Math.floor(Math.random() * 45) + 1;
                  }
              }
          }
    
          for(let i=0; i<index; i++){
              setTimeout(function(){
                  if(0<lottoArr[i] && lottoArr[i] < 11){
                      lotto_num_sub_id.innerHTML += "<div class='lotto_num_part' style='background-color:#fac400;'>" + lottoArr[i] + "</div>"
                  } else if(10<lottoArr[i] && lottoArr[i] < 21) {
                      lotto_num_sub_id.innerHTML += "<div class='lotto_num_part' style='background-color:#0000ff;'>" + lottoArr[i] + "</div>"
                  } else if(20<lottoArr[i] && lottoArr[i] < 31) {
                      lotto_num_sub_id.innerHTML += "<div class='lotto_num_part' style='background-color:#ff7272;'>" + lottoArr[i] + "</div>"
                  } else if(30<lottoArr[i] && lottoArr[i] < 41) {
                      lotto_num_sub_id.innerHTML += "<div class='lotto_num_part' style='background-color:#aaaaaa;'>" + lottoArr[i] + "</div>"
                  } else if(40<lottoArr[i] && lottoArr[i] < 46) {
                      lotto_num_sub_id.innerHTML += "<div class='lotto_num_part' style='background-color:#b0d840;'>" + lottoArr[i] + "</div>"
                  }
    
                  if(i == 5){
                      lotto_num_sub_id.innerHTML += "<div class='lotto_num_plus'> + </div>"
                  } 
              }, delay);
              delay = delay + 1000;
          }
      }