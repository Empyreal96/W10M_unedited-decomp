// PopConnectToPolicyDevice 
 
// local variable allocation has failed, the output may be wrong!
_BYTE *__fastcall PopConnectToPolicyDevice(int a1, unsigned __int16 *a2)
{
  char *v3; // r7
  unsigned __int16 *v4; // r5
  unsigned __int16 *i; // r4
  _BYTE *result; // r0
  int v8; // r5
  __int64 v9; // kr00_8
  unsigned int v10; // r4
  int v11; // r5 OVERLAPPED
  int v12; // r6 OVERLAPPED
  int v13; // r8
  int v14; // r2
  unsigned int *v15; // r1
  int v16[8]; // [sp+10h] [bp-20h] BYREF

  v16[0] = 0;
  v3 = (char *)&PopPolicyDeviceParameters + 20 * a1;
  v4 = (unsigned __int16 *)*((_DWORD *)v3 + 2);
  for ( i = *(unsigned __int16 **)v4; i != v4; i = *(unsigned __int16 **)i )
  {
    result = (_BYTE *)RtlCompareUnicodeString(i + 8, a2, 1);
    if ( !result )
      return result;
  }
  v8 = *a2;
  v9 = *(_QWORD *)v3;
  result = (_BYTE *)ExAllocatePoolWithTag(512, v8 + *(_DWORD *)v3, *((_DWORD *)v3 + 1));
  v10 = (unsigned int)result;
  if ( result )
  {
    memset(result, 0, v8 + v9);
    *(_DWORD *)(v10 + 20) = *(_DWORD *)v3 + v10;
    *(_WORD *)(v10 + 18) = *a2;
    RtlCopyUnicodeString((unsigned __int16 *)(v10 + 16), a2);
    *(_DWORD *)(v10 + 8) = a1;
    result = (_BYTE *)PopGetPolicyDeviceObject(v10 + 16, v16);
    v11 = (int)result;
    if ( result )
    {
      result = (_BYTE *)IoAllocateIrp(result[48], 0);
      v12 = (int)result;
      v13 = v16[0];
      if ( result )
      {
        result = (_BYTE *)IoRegisterPlugPlayNotification(
                            3,
                            0,
                            v16[0],
                            *(_DWORD *)(v11 + 8),
                            PopPolicyDeviceTargetChange,
                            v10,
                            v10 + 12);
        if ( (int)result >= 0 )
        {
          *(_QWORD *)(v10 + 24) = *(_QWORD *)&v11;
          result = (_BYTE *)(*((int (__fastcall **)(unsigned int))v3 + 3))(v10);
          v14 = *((_DWORD *)v3 + 2);
          v15 = *(unsigned int **)(v14 + 4);
          *(_DWORD *)v10 = v14;
          *(_DWORD *)(v10 + 4) = v15;
          if ( *v15 != v14 )
            sub_7F1984(result);
          *v15 = v10;
          *(_DWORD *)(v14 + 4) = v10;
          v12 = 0;
          v11 = 0;
          v10 = 0;
        }
        if ( v12 )
          result = (_BYTE *)IoFreeIrp(v12);
      }
      if ( v11 )
        result = (_BYTE *)ObfDereferenceObject(v11);
      if ( v13 )
        result = (_BYTE *)ObfDereferenceObject(v13);
    }
    if ( v10 )
      result = (_BYTE *)ExFreePoolWithTag(v10);
  }
  return result;
}
