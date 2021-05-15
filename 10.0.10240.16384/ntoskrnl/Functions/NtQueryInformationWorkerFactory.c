// NtQueryInformationWorkerFactory 
 
int __fastcall NtQueryInformationWorkerFactory(int a1, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  int v7; // r4
  int result; // r0
  _DWORD *v9; // r3
  _DWORD *v10; // r4
  int v11; // r2
  int v12; // r1
  int v13; // [sp+10h] [bp-88h] BYREF
  _DWORD v14[6]; // [sp+18h] [bp-80h] BYREF
  char v15; // [sp+30h] [bp-68h]
  char v16; // [sp+31h] [bp-67h]
  bool v17; // [sp+32h] [bp-66h]
  bool v18; // [sp+33h] [bp-65h]
  bool v19; // [sp+34h] [bp-64h]
  char v20; // [sp+35h] [bp-63h]
  char v21; // [sp+36h] [bp-62h]
  int v22; // [sp+38h] [bp-60h]
  int v23; // [sp+3Ch] [bp-5Ch]
  int v24; // [sp+40h] [bp-58h]
  int v25; // [sp+44h] [bp-54h]
  int v26; // [sp+48h] [bp-50h]
  int v27; // [sp+4Ch] [bp-4Ch]
  int v28; // [sp+50h] [bp-48h]
  int v29; // [sp+58h] [bp-40h]
  int v30; // [sp+5Ch] [bp-3Ch]
  int v31; // [sp+60h] [bp-38h]
  int v32; // [sp+64h] [bp-34h]
  int v33; // [sp+68h] [bp-30h]
  int v34; // [sp+6Ch] [bp-2Ch]
  int v35; // [sp+70h] [bp-28h]
  int v36; // [sp+74h] [bp-24h]
  _DWORD _78[14]; // [sp+78h] [bp-20h] BYREF

  _78[11] = a2;
  _78[13] = a4;
  _78[12] = a3;
  _78[10] = a1;
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( a2 != 7 )
    return -1073741821;
  if ( v7 )
  {
    if ( (a3 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a3 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a3 = *(_BYTE *)a3;
    *(_BYTE *)(a3 + 88) = *(_BYTE *)(a3 + 88);
    v9 = a5;
    if ( a5 )
    {
      if ( (unsigned int)a5 >= MmUserProbeAddress )
        v9 = (_DWORD *)MmUserProbeAddress;
      *v9 = 96;
    }
  }
  else if ( a5 )
  {
    *a5 = 96;
  }
  if ( a4 != 96 )
    return -1073741820;
  result = ObReferenceObjectByHandle(a1, 8, ExpWorkerFactoryObjectType, v7, &v13, 0);
  if ( result >= 0 )
  {
    v10 = (_DWORD *)v13;
    KeAcquireInStackQueuedSpinLock(*(unsigned int **)(v13 + 4), (unsigned int)_78);
    v14[0] = 0;
    v14[1] = 0;
    v14[2] = 0;
    v14[3] = 0;
    v14[4] = v10[12];
    v14[5] = v10[13];
    v15 = 0;
    v16 = 0;
    v17 = (v10[22] & 8) != 0;
    v11 = v10[1];
    v12 = *(_DWORD *)(v11 + 16);
    v18 = v12 == 0;
    v19 = v10[20] != 0;
    v20 = *(_BYTE *)(v11 + 20);
    v21 = *(_BYTE *)(v11 + 21);
    v22 = v10[21];
    v23 = v10[14];
    v24 = v10[15];
    v25 = v10[18];
    v26 = v12;
    v27 = v10[17];
    v28 = *(_DWORD *)(v11 + 12);
    v29 = 0;
    v30 = 0;
    v31 = v10[2];
    v32 = v10[3];
    v33 = *(_DWORD *)(v10[5] + 176);
    v34 = v10[6];
    v35 = v10[7];
    v36 = v10[24];
    KeReleaseInStackQueuedSpinLock((int)_78);
    ObfDereferenceObjectWithTag((int)v10);
    memmove(a3, (int)v14, 0x60u);
    result = 0;
  }
  return result;
}
