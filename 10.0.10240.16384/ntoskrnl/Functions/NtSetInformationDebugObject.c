// NtSetInformationDebugObject 
 
int __fastcall NtSetInformationDebugObject(int a1, int a2, char *a3, int a4, _DWORD *a5)
{
  int v8; // r4
  char *v9; // r1
  unsigned int v10; // r3
  _DWORD *v11; // r2
  _DWORD *v12; // r1
  int result; // r0
  int v14; // r5
  unsigned int *v15; // r8
  unsigned __int8 *v16; // r4
  int v17; // r9
  int v18; // r10
  unsigned int v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r3
  unsigned int v22; // r5
  unsigned int v23; // r1
  _DWORD _10[14]; // [sp+10h] [bp-20h] BYREF

  _10[12] = a3;
  _10[13] = a4;
  _10[0] = a4;
  _10[11] = a2;
  _10[10] = a1;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !v8 )
  {
    v11 = a5;
LABEL_14:
    if ( v11 )
      *v11 = 0;
    goto LABEL_16;
  }
  if ( a4 )
  {
    if ( ((unsigned __int8)a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v9 = &a3[a4];
    v10 = MmUserProbeAddress;
    if ( (unsigned int)&a3[a4] > MmUserProbeAddress || v9 < a3 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v10 = MmUserProbeAddress;
    }
  }
  else
  {
    v10 = MmUserProbeAddress;
  }
  v11 = a5;
  if ( a5 )
  {
    v12 = a5;
    if ( (unsigned int)a5 >= v10 )
      v12 = (_DWORD *)v10;
    *v12 = *v12;
    goto LABEL_14;
  }
LABEL_16:
  if ( a2 == 1 )
  {
    if ( a4 == 4 )
    {
      v14 = *(_DWORD *)a3;
      if ( (v14 & 0xFFFFFFFE) != 0 )
      {
        result = -1073741811;
      }
      else
      {
        result = ObReferenceObjectByHandle(a1, 4, DbgkDebugObjectType, v8, (int)_10, 0);
        if ( result >= 0 )
        {
          v15 = (unsigned int *)_10[0];
          v16 = (unsigned __int8 *)(_10[0] + 16);
          v17 = KeAbPreAcquire(_10[0] + 16, 0, 0);
          v18 = KfRaiseIrql(1);
          do
            v19 = __ldrex(v16);
          while ( __strex(v19 & 0xFE, v16) );
          __dmb(0xBu);
          if ( (v19 & 1) == 0 )
            ExpAcquireFastMutexContended((int)(v15 + 4), v17);
          if ( v17 )
            *(_BYTE *)(v17 + 14) |= 1u;
          v15[5] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v15[11] = v18;
          v20 = v15[14];
          if ( (v14 & 1) != 0 )
            v21 = v20 | 2;
          else
            v21 = v20 & 0xFFFFFFFD;
          v15[14] = v21;
          v15[5] = 0;
          v22 = v15[11];
          __dmb(0xBu);
          do
            v23 = __ldrex((unsigned int *)v16);
          while ( !v23 && __strex(1u, (unsigned int *)v16) );
          if ( v23 )
            ExpReleaseFastMutexContended(v15 + 4, v23);
          KfLowerIrql((unsigned __int8)v22);
          KeAbPostRelease((unsigned int)(v15 + 4));
          ObfDereferenceObject((int)v15);
          result = 0;
        }
      }
    }
    else
    {
      if ( v11 )
        *v11 = 4;
      result = -1073741820;
      _10[0] = -1073741820;
    }
  }
  else
  {
    result = -1073741811;
    _10[0] = -1073741811;
  }
  return result;
}
