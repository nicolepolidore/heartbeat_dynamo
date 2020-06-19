byte clicks = 0;
#define TIMER_LENGTH 2000
Timer heartbeatTimer;


void setup() {
  heartbeatTimer.set(TIMER_LENGTH);
}

void loop() {

  //check if timer is expired
  byte saturation = 0;
  byte dimness = 0;
  byte dimnessOne = 0;
  byte dimnessTwo=0;

  if (!heartbeatTimer.isExpired()) {
    //as time counts down, have the color fade

    int timerProgress = heartbeatTimer.getRemaining();

    saturation = 255 - (map(timerProgress, 0, TIMER_LENGTH, 0, 255));

    dimness = 255 - 0;
    dimnessOne = 255 - saturation; // smooth fade
    dimnessTwo = (dimnessOne * dimnessOne * dimnessOne) / 255; //flicker


  } else if (heartbeatTimer.isExpired()){
    // if time runs out, the blink goes dark

    saturation = 0;
    dimness = 0;
    dimnessOne =0;
    dimnessTwo = 0;
    }

  setColorOnFace(makeColorHSB(0, 150, 255),0);
  setColorOnFace(makeColorHSB(0, saturation, dimnessTwo),1);
  setColorOnFace(makeColorHSB(0, saturation, dimnessOne),2);
  setColorOnFace(makeColorHSB(0, saturation, dimnessOne),3);
  setColorOnFace(makeColorHSB(0, saturation, dimnessOne),4);
  setColorOnFace(makeColorHSB(0, saturation, dimnessTwo),5);



  if(buttonSingleClicked()){
  //reset our variables
  heartbeatTimer.set(TIMER_LENGTH);

  }



}
