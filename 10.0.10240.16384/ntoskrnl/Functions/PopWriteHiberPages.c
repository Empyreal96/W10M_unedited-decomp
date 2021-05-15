// PopWriteHiberPages 
 
int __fastcall PopWriteHiberPages(_DWORD *a1, int a2, unsigned int a3, unsigned int a4)
{
  int v6; // r0
  int v9; // r9
  int v10; // r4
  __int64 v11; // r0
  unsigned __int64 v12; // kr00_8
  int v13; // r3
  int v14; // r1
  _DWORD *v15; // r6
  unsigned int v16; // r2
  unsigned __int64 v17; // kr08_8
  int v18; // r9
  int v19; // r6
  int v20; // r2
  unsigned int v21; // r8
  int v22; // r3
  char *v23; // r5
  int v24; // r4
  unsigned int v25; // r7
  __int64 v26; // r0
  __int64 v27; // r4
  unsigned __int64 v28; // kr10_8
  unsigned int v30; // [sp+8h] [bp-F8h]
  unsigned int v31; // [sp+Ch] [bp-F4h]
  __int64 v32; // [sp+10h] [bp-F0h] BYREF
  _DWORD *v33; // [sp+18h] [bp-E8h]
  int v34; // [sp+1Ch] [bp-E4h] BYREF
  _DWORD *v35; // [sp+20h] [bp-E0h]
  int v36; // [sp+24h] [bp-DCh]
  unsigned __int64 v37; // [sp+28h] [bp-D8h] BYREF
  int v38[2]; // [sp+30h] [bp-D0h] BYREF
  int v39[2]; // [sp+38h] [bp-C8h] BYREF
  int v40; // [sp+40h] [bp-C0h] BYREF
  __int16 v41; // [sp+44h] [bp-BCh]
  __int16 v42; // [sp+46h] [bp-BAh]
  int v43; // [sp+4Ch] [bp-B4h]
  unsigned int v44; // [sp+50h] [bp-B0h]
  int v45; // [sp+54h] [bp-ACh]
  int v46; // [sp+58h] [bp-A8h]
  char v47; // [sp+5Ch] [bp-A4h] BYREF

  v6 = PopWatchdogTimerCount;
  v35 = a1;
  v9 = 0;
  HIDWORD(v32) = 0;
  if ( (PopWatchdogTimerCount & 0x1F) == 0 )
  {
    off_617B08(0);
    v6 = PopWatchdogTimerCount;
  }
  v10 = a1[30];
  LODWORD(v11) = v6 + 1;
  PopWatchdogTimerCount = v11;
  if ( v10 >= 0 )
  {
    v12 = (unsigned __int64)(a3 + a4) << 12;
    LODWORD(v11) = qword_61EEA8;
    if ( v12 > qword_61EEA8 )
    {
      v13 = a1[29];
      if ( v13 == 4 || v13 == 5 )
      {
        v9 = PopGetRemainingHibernateRangeDataSize(a1, v12, SHIDWORD(v12), v13);
        HIDWORD(v32) = v14;
      }
      v34 = MmGetNumberOfPhysicalPages(0);
      IoAddTriageDumpDataBlock((int)&v34, 4);
      KeBugCheckEx(160, 11, qword_61EEA8, a1[29], v9);
    }
    if ( a3 > 0xFFFFF )
      PopInternalError(663366);
    v15 = (_DWORD *)a1[26];
    v17 = (unsigned __int64)a4 << 12;
    v16 = HIDWORD(v17);
    HIDWORD(v11) = v17;
    v33 = v15;
    v30 = HIDWORD(v17);
    v31 = a4 << 12;
    v18 = a3 << 12;
    if ( a3 << 12 )
    {
      while ( 1 )
      {
        PopGetIoLocation(v39, v15, __PAIR64__(v16, HIDWORD(v11)), &v37);
        v19 = v37;
        v38[0] = v39[0];
        v38[1] = v39[1];
        if ( (unsigned int)v18 <= v37 )
          v19 = v18;
        v20 = a2 & 0xFFF;
        v21 = (unsigned int)(v20 + v19 + 4095) >> 12;
        if ( v21 > 0x10 )
        {
          v19 -= (v21 - 16) << 12;
          v21 = 16;
        }
        v40 = 0;
        v41 = 4 * (((unsigned int)(v20 + v19 + 4095) >> 12) + 7);
        v44 = a2 & 0xFFFFF000;
        v45 = v19;
        v22 = 1;
        v42 = 1;
        v46 = a2 & 0xFFF;
        v43 = a2;
        if ( v21 )
        {
          v23 = &v47;
          v24 = a2;
          v25 = v21;
          do
          {
            MmGetPhysicalAddress((int)&v32, v24, v20, v22);
            v20 = v32;
            v24 += 4096;
            v22 = v32 >> 12;
            *(_DWORD *)v23 = v22;
            v23 += 4;
            --v25;
          }
          while ( v25 );
          a1 = v35;
        }
        LODWORD(v26) = ReadTimeStampCounter();
        v27 = v26;
        v36 = (*(int (__fastcall **)(int *, int *))(a1[27] + 48))(v38, &v40);
        LODWORD(v11) = ReadTimeStampCounter();
        v18 -= v19;
        a2 += v19;
        qword_61EFA0 += v11 - v27;
        dword_61F160 += v21;
        v28 = __PAIR64__(v30, v31) + (unsigned int)v19;
        v16 = HIDWORD(v28);
        v30 = HIDWORD(v28);
        HIDWORD(v11) = v28;
        v31 = v28;
        if ( v36 < 0 )
          break;
        v15 = v33;
        if ( !v18 )
          return v11;
      }
      a1[30] = v36;
    }
  }
  return v11;
}
