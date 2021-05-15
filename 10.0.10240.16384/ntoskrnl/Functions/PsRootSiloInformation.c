// PsRootSiloInformation 
 
int __fastcall PsRootSiloInformation(_DWORD *a1, unsigned int a2, int *a3, int a4)
{
  int v4; // r4
  int v5; // r8
  int v6; // r10
  int v7; // r9
  int v8; // r6
  int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r9
  int *v12; // r2
  int *v13; // r6
  int v14; // r1
  unsigned int v15; // r1
  int v17; // [sp+0h] [bp-40h]
  int v18; // [sp+4h] [bp-3Ch]
  _DWORD *v19; // [sp+Ch] [bp-34h]
  int *v21; // [sp+18h] [bp-28h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]

  varg_r1 = a2;
  v21 = a3;
  v19 = a1;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = PsGetCurrentSilo();
  v18 = v7;
  v8 = KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
  v9 = KfRaiseIrql(1);
  v17 = v9;
  do
    v10 = __ldrex((unsigned __int8 *)&PspSiloListLock);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&PspSiloListLock, v8);
    v9 = v17;
  }
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  dword_61DA44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61DA5C = v9;
  if ( a2 < 4 )
  {
    v4 = -1073741789;
  }
  else
  {
    v11 = a2 - 4;
    v5 = 4;
    v12 = &PspSiloList;
    v13 = (int *)PspSiloList;
    v14 = v18;
    while ( v4 >= 0 && v13 != v12 )
    {
      if ( PsIsSiloInSilo((int)(v13 - 5), v14) )
      {
        if ( v11 < 4 )
        {
          v4 = -1073741789;
        }
        else
        {
          v11 -= 4;
          v5 += 4;
          v19[++v6] = *(v13 - 1);
          v12 = &PspSiloList;
          LOBYTE(v17) = dword_61DA5C;
        }
      }
      v13 = (int *)*v13;
    }
    LOBYTE(v9) = v17;
    v7 = v18;
  }
  dword_61DA44 = 0;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&PspSiloListLock);
  while ( !v15 && __strex(1u, (unsigned int *)&PspSiloListLock) );
  if ( v15 )
  {
    ExpReleaseFastMutexContended((unsigned int *)&PspSiloListLock, v15);
    LOBYTE(v9) = v17;
  }
  KfLowerIrql((unsigned __int8)v9);
  KeAbPostRelease((unsigned int)&PspSiloListLock);
  if ( v4 >= 0 )
  {
    *v19 = v6;
    *v21 = v5;
  }
  if ( v7 )
    ObfDereferenceObjectWithTag(v7);
  return v4;
}
