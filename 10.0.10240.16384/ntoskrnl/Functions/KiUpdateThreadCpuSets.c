// KiUpdateThreadCpuSets 
 
int __fastcall KiUpdateThreadCpuSets(int a1, _DWORD *a2, int a3, unsigned int *a4)
{
  int v5; // r3
  int v6; // r5
  int v8; // r4
  unsigned int *v9; // r6
  int v10; // r0
  _DWORD *v12; // [sp+4h] [bp-1Ch]
  int v13; // [sp+8h] [bp-18h] BYREF
  unsigned int *v14; // [sp+Ch] [bp-14h] BYREF

  v13 = a3;
  v14 = a4;
  v5 = *(_DWORD *)(a1 + 76);
  v6 = 0;
  v13 = 0;
  if ( (v5 & 8) == 0 )
  {
    v8 = KiAcquireThreadStateLock(a1, &v13, &v14);
    KiComputeThreadAffinity(a1);
    v6 = v13;
    v12 = a2;
    v9 = v14;
    v10 = KiRescheduleThreadAfterAffinityChange((_BYTE *)a1, a1 + 356, v8, v13, (int)v14, v12);
    if ( v6 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v6 + 24) = 0;
    }
    if ( v9 )
    {
      __dmb(0xBu);
      *v9 = 0;
    }
    if ( !v10 )
      v6 = 0;
  }
  return v6;
}
