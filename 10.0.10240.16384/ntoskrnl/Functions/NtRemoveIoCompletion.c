// NtRemoveIoCompletion 
 
int __fastcall NtRemoveIoCompletion(int a1, _DWORD *a2, _DWORD *a3, unsigned int a4, unsigned int a5)
{
  _DWORD *v5; // r6
  _DWORD *v6; // r8
  __int64 *v8; // r10
  unsigned int v9; // r1
  _DWORD *v10; // r2
  _DWORD *v11; // r2
  __int64 *v12; // r3
  int v13; // r4
  unsigned int v15; // [sp+18h] [bp-50h] BYREF
  int v16; // [sp+1Ch] [bp-4Ch] BYREF
  __int64 v17; // [sp+20h] [bp-48h]
  int *v18; // [sp+28h] [bp-40h] BYREF
  __int64 v19; // [sp+30h] [bp-38h] BYREF
  _DWORD _38[18]; // [sp+38h] [bp-30h] BYREF

  v5 = (_DWORD *)a4;
  _38[17] = a4;
  v6 = a3;
  _38[16] = a3;
  _38[15] = a2;
  _38[14] = a1;
  v8 = 0;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v15 = v9;
  if ( v9 )
  {
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      a3 = (_DWORD *)MmUserProbeAddress;
    *a3 = *a3;
    v10 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
    v11 = (_DWORD *)a4;
    if ( a4 >= MmUserProbeAddress )
      v11 = (_DWORD *)MmUserProbeAddress;
    *v11 = *v11;
    v12 = (__int64 *)a5;
    if ( a5 )
    {
      v8 = &v19;
      if ( a5 >= MmUserProbeAddress )
        v12 = (__int64 *)MmUserProbeAddress;
      v17 = *v12;
      v19 = v17;
    }
  }
  else if ( a5 )
  {
    v8 = (__int64 *)a5;
  }
  v13 = ObReferenceObjectByHandle(a1, 2, IoCompletionObjectType, v9, &v16);
  if ( v13 >= 0 )
  {
    v13 = IoRemoveIoCompletion(v16, (int)_38, &v18, 1u, &v15, v15, v8, 0);
    ObfDereferenceObject(v16);
    if ( !v13 )
    {
      *a2 = _38[0];
      *v6 = _38[1];
      *v5 = _38[2];
      v5[1] = _38[3];
    }
  }
  return v13;
}
