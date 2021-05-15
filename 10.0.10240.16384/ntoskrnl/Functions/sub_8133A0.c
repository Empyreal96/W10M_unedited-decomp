// sub_8133A0 
 
void sub_8133A0()
{
  int v0; // r5
  int v1; // r6
  int v2; // r4
  int v3; // [sp+20h] [bp-F8h]

  v2 = ZwWaitForSingleObject();
  if ( v2 >= 0 )
    JUMPOUT(0x7A4A12);
  if ( v1 )
    goto LABEL_7;
  ZwResetEvent();
  v2 = ZwDeviceIoControlFile();
  if ( v2 == v0 )
  {
    if ( ZwWaitForSingleObject() < 0 )
      goto LABEL_10;
    v2 = v3;
  }
  if ( v2 >= 0 )
  {
LABEL_7:
    if ( v2 >= 0 )
      JUMPOUT(0x7A4A18);
  }
LABEL_10:
  JUMPOUT(0x7A4A22);
}
