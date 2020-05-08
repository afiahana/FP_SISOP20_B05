#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[]){
  if(argc < 2){
    printf(0, "stat: Missing Operand\n");
    printf(1, "Need More Argument\n");
    exit();
  }

  struct stat st;
  int fd;
  char *current_path = argv[1];

  if((fd = open(current_path, 0)) < 0){
    printf(2, "stat: cannot open %s\n", current_path);
  }
  
  if(fstat(fd, &st) < 0){
    printf(2, "stat: cannot stat %s : No such file or directory\n", current_path);
    close(fd);
  }
  
  switch(st.type){
  case T_FILE:
    printf(1, "File: %s\n", current_path);
    printf(1, "Size: %d\t\tType: File\n", st.size);
    printf(1, "Device: %d\t\tInode: %d\t\tLinks: %d\n", st.dev, st.ino, st.nlink);
    break;
  
  case T_DIR:
    printf(1, "File: %s\n", current_path);
    printf(1, "Size: %d\t\tType: Directory\n", st.size);
    printf(1, "Device: %d\t\tInode: %d\t\tLinks: %d\n", st.dev, st.ino, st.nlink);
    break;

  case T_DEV:
    printf(1, "File: %s\n", current_path);
    printf(1, "Size: %d\t\tType: Device\n", st.size);
    printf(1, "Device: %d \t\tInode: %d\t\tLinks: %d\n", st.dev, st.ino, st.nlink);
    break;
  }
  exit();
}