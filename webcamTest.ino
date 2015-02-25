// Sketch to upload pictures to Dropbox when motion is detected
#include <Bridge.h>
#include <Process.h>


Process picture;

String filename;
String path = "/mnt/sda1/";

void setup() {
  
  Bridge.begin();
}

void loop(void) 
{
  
    // Generate filename with timestamp
    filename = "";
    picture.runShellCommand("date +%s");
    while(picture.running());

    while (picture.available()>0) {
      char c = picture.read();
      filename += c;
    } 
    filename.trim();
    filename += ".png";
 
    // Take picture
    picture.runShellCommand("fswebcam " + path + filename + " -r 1280x720");
    while(picture.running());
    
    delay(5000); 

}
