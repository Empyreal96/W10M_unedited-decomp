// NtRemoveIoCompletionEx 
 
int __fastcall NtRemoveIoCompletionEx(int a1, int a2, unsigned int a3, int *a4, unsigned int a5, unsigned __int8 a6)
{
  unsigned int v7; // r6
  __int64 *v8; // r4
  int v9; // r4
  __int64 *v10; // r10
  int *v11; // r2
  int v12; // r0
  int v13; // r3
  int **v14; // r5
  int v15; // r6
  int v17; // [sp+14h] [bp-94h] BYREF
  int v18; // [sp+18h] [bp-90h]
  int v19; // [sp+1Ch] [bp-8Ch] BYREF
  int v20; // [sp+20h] [bp-88h]
  __int64 *v21; // [sp+24h] [bp-84h]
  int v22; // [sp+28h] [bp-80h]
  int v23; // [sp+2Ch] [bp-7Ch]
  __int64 v24; // [sp+30h] [bp-78h]
  int *v25; // [sp+38h] [bp-70h]
  int v26; // [sp+3Ch] [bp-6Ch]
  __int64 v27; // [sp+40h] [bp-68h] BYREF
  _DWORD _48[30]; // [sp+48h] [bp-60h] BYREF

  _48[26] = a1;
  _48[27] = a2;
  _48[29] = a4;
  v7 = a3;
  _48[28] = a3;
  v22 = a2;
  v23 = a1;
  v17 = a1;
  v26 = a2;
  v25 = a4;
  v8 = (__int64 *)a5;
  v20 = 0;
  v19 = 0;
  if ( !a3 || a3 > 0xFFFFFFF )
    return -1073741811;
  v10 = 0;
  v21 = 0;
  v18 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v18 )
  {
    ProbeForWrite(a2, 16 * a3, 4);
    v11 = a4;
    if ( (unsigned int)a4 >= MmUserProbeAddress )
      v11 = (int *)MmUserProbeAddress;
    *v11 = *v11;
    if ( a5 )
    {
      v10 = &v27;
      v21 = &v27;
      if ( a5 >= MmUserProbeAddress )
        v8 = (__int64 *)MmUserProbeAddress;
      v24 = *v8;
      v27 = v24;
    }
  }
  else if ( a5 )
  {
    v10 = (__int64 *)a5;
  }
  if ( v7 <= 0x10 )
    goto LABEL_23;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v13 = 40;
    else
      v13 = 32;
    v12 = ExAllocatePoolWithTagPriority(512, 4 * v7, 538996553, v13);
  }
  else
  {
    v12 = ExAllocatePoolWithTag(512, 4 * v7, 538996553);
  }
  v14 = (int **)v12;
  if ( !v12 )
  {
    v7 = 16;
LABEL_23:
    v14 = (int **)_48;
  }
  v9 = ObReferenceObjectByHandle(v23, 2, IoCompletionObjectType, v18, &v17);
  if ( v9 < 0 )
  {
    v15 = v20;
  }
  else
  {
    v9 = IoRemoveIoCompletion(v17, v22, v14, v7, (unsigned int *)&v19, v18, v10, a6);
    ObfDereferenceObject(v17);
    v15 = v19;
  }
  if ( v14 != _48 )
    ExFreePoolWithTag((unsigned int)v14);
  if ( v9 >= 0 )
    *a4 = v15;
  return v9;
}
