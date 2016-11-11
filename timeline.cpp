#include <stdio>

#include <timeline.h>

timeline() {
   head = newFrame();
}

~timeline() {
}

int deleteFrame() {
}

int duplicateFrame() {
}

int selectFrame() {
}

int moveFrame() {
}

int modifyFrame() {
}

int loadframes() {
}

int findFrame() {
}

timelineFrame newFrame(int id) {
   new timelineFrame f;
   f->id=id;
   f->next = NULL;
   return f;
}
