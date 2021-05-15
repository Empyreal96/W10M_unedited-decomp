// MmCopyVirtualMemory 
 
int __fastcall MmCopyVirtualMemory(int a1, unsigned int a2, int a3, int a4, unsigned int a5, char a6, unsigned int *a7)
{
  unsigned int v7; // r10
  unsigned int *v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r8
  unsigned int v11; // r9
  int v12; // r1
  int v13; // lr
  char v14; // r2
  unsigned int v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r1
  int v18; // r1
  _BYTE *v20; // [sp+8h] [bp-310h]
  int v21; // [sp+Ch] [bp-30Ch]
  int v22; // [sp+10h] [bp-308h]
  int v23; // [sp+1Ch] [bp-2FCh]
  unsigned int v24; // [sp+30h] [bp-2E8h]
  unsigned int v26; // [sp+3Ch] [bp-2DCh]
  int v27; // [sp+68h] [bp-2B0h]
  int v28; // [sp+7Ch] [bp-29Ch]
  _BYTE v29[24]; // [sp+88h] [bp-290h] BYREF
  int v30; // [sp+A0h] [bp-278h] BYREF
  __int16 v31; // [sp+A4h] [bp-274h]
  __int16 v32; // [sp+A6h] [bp-272h]
  unsigned int v33; // [sp+B0h] [bp-268h]
  unsigned int v34; // [sp+B4h] [bp-264h]
  int v35; // [sp+B8h] [bp-260h]
  _BYTE v36[544]; // [sp+F8h] [bp-220h] BYREF

  v26 = a4;
  v7 = a2;
  v21 = a1;
  v8 = a7;
  if ( a5 )
  {
    *a7 = 0;
    v9 = 0;
    if ( (BYTE2(MiFlags) & 3u) <= 1 && !*(_DWORD *)(a1 + 272) )
      v9 = 2;
    v22 = a2;
    v23 = a4;
    v10 = a5;
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = 0;
LABEL_6:
    if ( a5 < 0x200 || (v9 & 2) == 0 )
    {
      v9 &= 0xFFFFFFFD;
      v11 = 0x10000;
      if ( a5 <= 0x10000 )
        v11 = a5;
      if ( a5 <= 0x200 )
      {
        v20 = v36;
        goto LABEL_19;
      }
      while ( 1 )
      {
        v20 = (_BYTE *)ExAllocatePoolWithTag(1, v11, 2001890637);
        if ( v20 )
          break;
        v11 >>= 1;
        if ( v11 <= 0x200 )
        {
          v20 = v36;
LABEL_18:
          a1 = v21;
          goto LABEL_19;
        }
      }
      v9 |= 1u;
      goto LABEL_18;
    }
    v11 = 57344;
    if ( a5 <= 0xE000 )
      v11 = a5;
LABEL_19:
    while ( v10 )
    {
      if ( v10 < v11 )
        v11 = v10;
      KiStackAttachProcess(a1, 0, (int)v29);
      v27 = 0;
      v12 = v22;
      if ( v22 == v7 && a6 && (v7 + a5 > MmUserProbeAddress || v7 + a5 < v7) )
        *(_BYTE *)MmUserProbeAddress = 0;
      v13 = (v9 >> 1) & 1;
      if ( v13 )
      {
        v30 = 0;
        v31 = 4 * ((((v22 & 0xFFF) + v11 + 4095) >> 12) + 7);
        v32 = 0;
        v12 = v22;
        v33 = v22 & 0xFFFFF000;
        v35 = v22 & 0xFFF;
        v34 = v11;
        v8 = a7;
      }
      v14 = *(_BYTE *)(v24 + 76);
      *(_BYTE *)(v24 + 76) = v14 | 0x20;
      v28 = (unsigned __int8)(v14 & 0x20) >> 5;
      if ( v13 )
        MmProbeAndLockPages((int)&v30);
      else
        memmove((int)v20, v12, v11);
      if ( !v28 )
        *(_BYTE *)(v24 + 76) &= 0xDFu;
      if ( ((v9 >> 1) & 1) != 0 )
      {
        v27 = MmMapLockedPagesSpecifyCache((int)&v30, 0, 1, 0, 0, -1073741792);
        if ( !v27 )
        {
          MmUnlockPages((int)&v30);
          v9 &= 0xFFFFFFFD;
          KiUnstackDetachProcess((unsigned int)v29, 0);
          a1 = v21;
          goto LABEL_6;
        }
      }
      KiUnstackDetachProcess((unsigned int)v29, 0);
      KiStackAttachProcess(a3, 0, (int)v29);
      if ( v22 == v7 && a6 )
      {
        v15 = v26;
        v16 = v26 + a5 - 1;
        if ( v26 > v16 || v16 >= MmUserProbeAddress )
          ExRaiseAccessViolation();
        v17 = (v16 & 0xFFFFF000) + 4096;
        do
        {
          *(_BYTE *)v15 = *(_BYTE *)v15;
          v15 = (v15 & 0xFFFFF000) + 4096;
        }
        while ( v15 != v17 );
      }
      if ( ((v9 >> 1) & 1) != 0 )
        v18 = v27;
      else
        v18 = (int)v20;
      memmove(v23, v18, v11);
      KiUnstackDetachProcess((unsigned int)v29, 0);
      if ( (v9 & 2) != 0 )
        MmUnlockPages((int)&v30);
      v10 -= v11;
      v22 += v11;
      v23 += v11;
      a1 = v21;
    }
    if ( (v9 & 1) != 0 )
      ExFreePoolWithTag((unsigned int)v20);
    *v8 = a5;
  }
  return 0;
}
