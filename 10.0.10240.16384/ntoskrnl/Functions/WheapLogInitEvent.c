// WheapLogInitEvent 
 
int WheapLogInitEvent()
{
  int result; // r0
  unsigned int v1; // r7
  int *v2; // r4
  int v3; // r6
  int v4; // [sp+4h] [bp-68h] BYREF
  int v5[25]; // [sp+8h] [bp-64h] BYREF

  v4 = 1048 * dword_641930;
  result = ExAllocatePoolWithTag(512, 1048 * dword_641930, 1634035799);
  v1 = result;
  if ( result )
  {
    v2 = (int *)dword_641934;
    if ( (int *)dword_641934 != &dword_641934 )
    {
      v3 = result;
      do
      {
        memmove(v3, (int)v2, 0x418u);
        v2 = (int *)*v2;
        v3 += 1048;
      }
      while ( v2 != &dword_641934 );
    }
    v5[1] = (int)&dword_641930;
    v5[2] = 0;
    v5[3] = 4;
    v5[4] = 0;
    v5[0] = 10;
    v5[5] = (int)v5;
    v5[6] = 0;
    v5[7] = 4;
    v5[8] = 0;
    v5[9] = (int)&v4;
    v5[10] = 0;
    v5[11] = 4;
    v5[12] = 0;
    v5[13] = v1;
    v5[14] = 0;
    v5[15] = v4;
    v5[16] = 0;
    if ( EtwEventEnabled(WheapEtwHandle, unk_6197CC, (int)EVENT_WHEA_INIT_OP) == 1 )
      result = sub_81B8C0();
    else
      result = ExFreePoolWithTag(v1);
  }
  return result;
}
