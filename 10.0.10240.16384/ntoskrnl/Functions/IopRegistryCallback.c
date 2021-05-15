// IopRegistryCallback 
 
int __fastcall IopRegistryCallback(int a1)
{
  __int64 v1; // r3
  __int16 **v2; // r5
  int result; // r0
  int v4; // r0
  char v5[4]; // [sp+18h] [bp-20h] BYREF
  __int16 *v6; // [sp+1Ch] [bp-1Ch] BYREF
  char v7[24]; // [sp+20h] [bp-18h] BYREF

  HIDWORD(v1) = a1;
  v2 = &(&IopRegistryRegisteredCallbacks)[14 * a1];
  RtlInitUnicodeString((unsigned int)v7, (unsigned __int16 *)*v2);
  LODWORD(v1) = IopRegistryCallback;
  *((_QWORD *)v2 + 5) = v1;
  v2[8] = 0;
  if ( ((unsigned int)v2[5] & 1) == 0
    || (((void (__fastcall *)(__int16 *))v2[2])(v2[3]), result = ZwNotifyChangeKey(), result < 0) )
  {
    if ( IopRegistryOpenDeepestPath(v7, &v6, v5) < 0 )
      goto LABEL_8;
    v4 = ZwClose();
    v2[4] = v6;
    if ( v5[0] == 1 )
      return sub_817954(v4);
    result = ZwNotifyChangeKey();
    if ( result < 0 )
    {
LABEL_8:
      result = ZwClose();
      v2[1] = 0;
    }
  }
  return result;
}
