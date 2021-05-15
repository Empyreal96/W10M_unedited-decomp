// _CmDeleteDeviceContainerWorker 
 
int __fastcall CmDeleteDeviceContainerWorker(int a1, int a2, __int16 a3)
{
  int v3; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r5
  int v8; // r0
  int v9; // r6
  int v10; // r7
  int v12; // [sp+14h] [bp-2Ch] BYREF
  int v13; // [sp+18h] [bp-28h]
  int v14; // [sp+1Ch] [bp-24h]

  v3 = 0;
  v13 = a2;
  v14 = a1;
  if ( a3 )
    return -1073741811;
  v4 = CmDeleteDeviceContainerRegKey(a1, a2, 336);
  if ( !v4 || v4 == -1073741772 || v4 == -1073741811 || v4 == -1073741637 || (v3 = v4, v4 >= 0) )
  {
    v7 = 0;
    v12 = 0;
    do
    {
      v8 = CmGetDeviceContainerMappedPropertyKeys(v4, v5, v6);
      if ( v8 != -1073741789 )
        goto LABEL_16;
      if ( RtlULongLongToULong(0, 0, &v12) < 0 )
      {
        v8 = -1073741811;
        goto LABEL_18;
      }
      if ( v7 )
        ExFreePoolWithTag(v7);
      v4 = ExAllocatePoolWithTag(1, v12, 1380994640);
      v7 = v4;
    }
    while ( v4 );
    v8 = -1073741801;
LABEL_16:
    if ( v8 && v8 != -1073741275 )
    {
LABEL_18:
      v3 = v8;
      goto LABEL_25;
    }
    if ( v3 >= 0 )
    {
      v9 = v13;
      v10 = v14;
      v8 = CmDeleteDeviceContainerRegKey(v14, v13, 80);
      if ( v8 && v8 != -1073741772 && v8 != -1073741811 )
        goto LABEL_18;
      CmRaiseDeleteEvent(v10, v9, 5);
    }
LABEL_25:
    if ( v7 )
      ExFreePoolWithTag(v7);
  }
  return v3;
}
