// EtwpTraceOpticalIoInit 
 
int *__fastcall EtwpTraceOpticalIoInit(int *result)
{
  int v1; // r4
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r2
  int v6; // r2
  int v7[2]; // [sp+8h] [bp-20h] BYREF
  int v8[6]; // [sp+10h] [bp-18h] BYREF

  v1 = (int)result;
  v2 = *(unsigned __int8 *)result[24];
  if ( v2 == 3 )
    goto LABEL_13;
  if ( v2 == 4 )
    goto LABEL_12;
  if ( v2 != 9 )
  {
    if ( v2 != 14 )
      return result;
    result = (int *)EtwpGetScsiPassThroughCdb((int)result);
    if ( !result )
      return result;
    v3 = *(unsigned __int8 *)result;
    if ( v3 != 40 && v3 != 168 )
    {
      if ( v3 != 42 && v3 != 170 )
      {
        if ( v3 != 53 )
          return result;
        goto LABEL_11;
      }
LABEL_12:
      v4 = 315;
      goto LABEL_14;
    }
LABEL_13:
    v4 = 314;
    goto LABEL_14;
  }
LABEL_11:
  v4 = 316;
LABEL_14:
  v5 = *(_DWORD *)(v1 + 80);
  v7[0] = v1;
  if ( v5 )
    v6 = *(_DWORD *)(v5 + 880);
  else
    v6 = -1;
  v7[1] = v6;
  v8[0] = (int)v7;
  v8[1] = 0;
  v8[2] = 8;
  v8[3] = 0;
  return EtwTraceKernelEvent(v8, 1, 0x80000002, v4, 5249283);
}
