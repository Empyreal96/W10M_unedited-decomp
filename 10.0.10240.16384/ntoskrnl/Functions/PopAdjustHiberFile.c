// PopAdjustHiberFile 
 
int PopAdjustHiberFile()
{
  int result; // r0
  char v1[8]; // [sp+0h] [bp-20h] BYREF
  _DWORD v2[2]; // [sp+8h] [bp-18h] BYREF
  char v3; // [sp+10h] [bp-10h] BYREF

  PopCalculateHiberFileSize(v2, v1);
  result = PopResizeHiberFile(v2[0], v2[1], &v3);
  if ( result >= 0 )
    byte_61EA56 = v1[0];
  return result;
}
