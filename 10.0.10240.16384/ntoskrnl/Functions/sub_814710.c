// sub_814710 
 
void sub_814710()
{
  int v0; // r5
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int v4; // r0
  int v5; // [sp+68h] [bp-158h]
  int v6; // [sp+6Ch] [bp-154h]
  int v7; // [sp+78h] [bp-148h]
  int v8; // [sp+7Ch] [bp-144h]
  int v9[78]; // [sp+88h] [bp-138h] BYREF

  if ( ZwWaitForSingleObject() >= 0 )
    JUMPOUT(0x7A7BC0);
  memset(v9, 0, 284);
  v9[0] = 284;
  if ( RtlGetVersion(v9, v1, v2, v3) >= 0 && v9[1] == 5 && !v9[2] )
  {
    ZwResetEvent();
    v4 = ZwDeviceIoControlFile();
    if ( v4 == v0 )
    {
      if ( ZwWaitForSingleObject() < 0 )
        goto LABEL_15;
      v4 = 0;
    }
    if ( v4 >= 0 && (v7 != 29 || v5 != 14848 || v6 || v8 != 1) )
      JUMPOUT(0x7A7BC6);
  }
LABEL_15:
  JUMPOUT(0x7A7BE4);
}
