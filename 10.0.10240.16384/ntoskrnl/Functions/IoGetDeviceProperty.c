// IoGetDeviceProperty 
 
int __fastcall IoGetDeviceProperty(int a1, __int16 a2, unsigned int a3, int *a4, unsigned int *a5)
{
  int v8; // r1
  int v9; // r5
  int v10; // r0
  unsigned __int16 *v11; // r5
  int v13; // r4
  unsigned int v14; // r3
  int v15; // r2
  int v16; // r1
  int v17; // r3
  int v18; // r0
  int v19; // r4
  int v20; // r1
  unsigned int v21; // r2
  int v22; // r4
  int v23; // r1
  unsigned int v24; // r2
  unsigned int v25; // r0
  int v26; // r0
  int v27; // r3
  int v28; // r2
  int v29; // r0
  unsigned int *v30; // r1
  unsigned int v31; // r3
  unsigned __int8 v32; // r5
  unsigned int v33; // r1
  int v34; // r10
  unsigned int v35; // r4
  int v36; // r0
  unsigned int v37; // r10
  int v38; // [sp+10h] [bp-80h] BYREF
  int v39; // [sp+14h] [bp-7Ch]
  int v40; // [sp+18h] [bp-78h] BYREF
  int v41; // [sp+1Ch] [bp-74h] BYREF
  int v42[4]; // [sp+20h] [bp-70h] BYREF
  char v43[8]; // [sp+30h] [bp-60h] BYREF
  int v44; // [sp+38h] [bp-58h]

  *a5 = 0;
  v8 = a2 & 0xFFF;
  if ( !a1 )
    return -1073741808;
  v9 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v9 || (*(_DWORD *)(v9 + 268) & 0x20000) != 0 )
  {
    if ( v8 != 18 && (v8 != 15 || !v9) )
      PpvUtilFailDriver(2);
    return -1073741808;
  }
  switch ( v8 )
  {
    case 0:
      v15 = 1;
      goto LABEL_19;
    case 1:
      v15 = 2;
      goto LABEL_16;
    case 2:
      v15 = 3;
LABEL_16:
      v16 = 7;
      goto LABEL_69;
    case 3:
      *a5 = a3;
      return PiGetDeviceRegistryProperty(a1);
    case 4:
      v18 = *(_DWORD *)(v9 + 364);
      if ( !v18 )
      {
        *a5 = 0;
        return 0;
      }
      v25 = PnpDetermineResourceListSize(v18);
      *a5 = v25;
      if ( v25 <= a3 )
      {
        memmove((int)a4, *(_DWORD *)(v9 + 364), v25);
        return 0;
      }
      return -1073741789;
    case 5:
      v15 = 8;
      goto LABEL_19;
    case 6:
      v15 = 9;
      goto LABEL_19;
    case 7:
      v15 = 10;
      goto LABEL_19;
    case 8:
      v15 = 12;
      goto LABEL_19;
    case 9:
      v15 = 13;
      goto LABEL_19;
    case 10:
      v15 = 14;
      goto LABEL_19;
    case 11:
      v38 = a3 + 8;
      v10 = ExAllocatePoolWithTag(1, a3 + 8, 1869181008);
      v11 = (unsigned __int16 *)v10;
      if ( !v10 )
        return sub_7E7A9C();
      v13 = ObQueryNameStringMode(a1, v10, v38, a5, 0);
      if ( v13 == -1073741820 )
        v13 = -1073741789;
      if ( v13 < 0 )
      {
        *a5 -= 8;
      }
      else if ( *v11 )
      {
        v14 = *v11 + 2;
        *a5 = v14;
        if ( v14 > a3 )
        {
          v13 = -1073741789;
        }
        else
        {
          memmove((int)a4, *((_DWORD *)v11 + 1), *v11);
          *(_WORD *)((char *)a4 + *v11) = 0;
        }
      }
      else
      {
        *a5 = 0;
      }
      ExFreePoolWithTag((unsigned int)v11);
      return v13;
    case 12:
      v13 = PnpBusTypeGuidGet(*(unsigned __int16 *)(v9 + 316), v42);
      if ( v13 < 0 )
        return v13;
      *a5 = 16;
      if ( a3 < 0x10 )
        return -1073741789;
      *a4 = v42[0];
      a4[1] = v42[1];
      a4[2] = v42[2];
      a4[3] = v42[3];
      return v13;
    case 13:
      if ( *(_DWORD *)(v9 + 308) == -1 )
        return -1073741772;
      *a5 = 4;
      if ( a3 < 4 )
        return -1073741789;
      v17 = *(_DWORD *)(v9 + 308);
      goto LABEL_28;
    case 14:
      if ( *(int *)(v9 + 312) < 0 )
        return -1073741772;
      *a5 = 4;
      if ( a3 < 4 )
        return -1073741789;
      v17 = *(_DWORD *)(v9 + 312);
LABEL_28:
      *a4 = v17;
      return 0;
    case 15:
      v15 = 23;
      goto LABEL_19;
    case 16:
      if ( PpIrpQueryCapabilities(a1, v43) < 0 )
        return -1073741772;
      v17 = v44;
      if ( v44 == -1 )
        return -1073741772;
      *a5 = 4;
      if ( a3 >= 4 )
        goto LABEL_28;
      return -1073741789;
    case 17:
      v15 = 17;
      v16 = 4;
      goto LABEL_69;
    case 18:
      if ( v9 == IopRootDeviceNode )
      {
        v28 = 0;
        v13 = 0;
        goto LABEL_72;
      }
      if ( !*(_DWORD *)(v9 + 24) )
        return -1073741808;
      while ( 1 )
      {
        v38 = 4;
        v29 = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v9 + 24), 0, 11, (int)&v41, (int)&v40, (int)&v38);
        v13 = v29;
        if ( v29 < 0 || v41 != 4 || v38 != 4 )
          break;
        if ( (v40 & 0x20) != 0 )
        {
          v28 = 1;
        }
        else if ( (v40 & 0x40) != 0 )
        {
          v28 = 2;
        }
        else if ( (v40 & 0x400) != 0 )
        {
          v28 = 3;
        }
        else
        {
          v28 = 0;
        }
        v9 = *(_DWORD *)(v9 + 8);
        if ( v28 || v9 == IopRootDeviceNode )
          goto LABEL_89;
      }
      v28 = 2;
LABEL_89:
      if ( v29 < 0 )
      {
        if ( v29 == -1073741275 )
          return -1073741772;
        v27 = -1073741810;
LABEL_44:
        if ( v13 == v27 )
          return -1073741772;
        return v13;
      }
LABEL_72:
      *a5 = 4;
      if ( a3 < 4 )
        return -1073741789;
      *a4 = v28;
      return v13;
    case 19:
      *a5 = 4;
      if ( a3 < 4 )
        return -1073741789;
      PpHotSwapGetDevnodeRemovalPolicy(v9, 1, a4);
      return 0;
    case 20:
      v19 = KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
      v20 = KfRaiseIrql(1);
      v39 = v20;
      do
        v21 = __ldrex((unsigned __int8 *)&PiResourceListLock);
      while ( __strex(v21 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
      __dmb(0xBu);
      if ( (v21 & 1) == 0 )
      {
        ExpAcquireFastMutexContended((int)&PiResourceListLock, v19);
        v20 = v39;
      }
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
      dword_630824 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_63083C = v20;
      v30 = *(unsigned int **)(v9 + 296);
      if ( v30 )
      {
        v31 = *v30;
        *a5 = *v30;
        if ( v31 > a3 )
        {
          v13 = -1073741789;
          goto LABEL_101;
        }
        memmove((int)a4, (int)v30, *v30);
      }
      else
      {
        *a5 = 0;
      }
      v13 = 0;
LABEL_101:
      dword_630824 = 0;
      v32 = dword_63083C;
      __dmb(0xBu);
      do
        v33 = __ldrex(&PiResourceListLock);
      while ( !v33 && __strex(1u, &PiResourceListLock) );
      goto LABEL_110;
    case 21:
      v22 = KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
      v23 = KfRaiseIrql(1);
      v39 = v23;
      do
        v24 = __ldrex((unsigned __int8 *)&PiResourceListLock);
      while ( __strex(v24 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
      __dmb(0xBu);
      if ( (v24 & 1) == 0 )
      {
        ExpAcquireFastMutexContended((int)&PiResourceListLock, v22);
        v23 = v39;
      }
      if ( v22 )
        *(_BYTE *)(v22 + 14) |= 1u;
      dword_630824 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_63083C = v23;
      if ( !*(_DWORD *)(v9 + 284) || (v34 = *(_DWORD *)(v9 + 288)) == 0 )
      {
        *a5 = 0;
LABEL_106:
        v13 = 0;
        goto LABEL_107;
      }
      v35 = ((int (*)(void))PnpDetermineResourceListSize)();
      v36 = PnpDetermineResourceListSize(v34);
      *a5 = v35 + v36;
      v37 = v36;
      if ( v35 + v36 <= a3 )
      {
        memmove((int)a4, *(_DWORD *)(v9 + 284), v35);
        memmove((int)a4 + v35, *(_DWORD *)(v9 + 288), v37);
        goto LABEL_106;
      }
      v13 = -1073741789;
LABEL_107:
      dword_630824 = 0;
      v32 = dword_63083C;
      __dmb(0xBu);
      do
        v33 = __ldrex(&PiResourceListLock);
      while ( !v33 && __strex(1u, &PiResourceListLock) );
LABEL_110:
      if ( v33 )
        ExpReleaseFastMutexContended(&PiResourceListLock, v33);
      KfLowerIrql(v32);
      KeAbPostRelease((unsigned int)&PiResourceListLock);
      break;
    case 22:
      v15 = 37;
LABEL_19:
      v16 = 1;
LABEL_69:
      if ( !*(_DWORD *)(v9 + 24) )
        return -1073741808;
      *a5 = a3;
      v26 = PiGetDeviceRegProperty(*(_DWORD *)(v9 + 24), v16, v16, v15, a4, a5);
      v27 = -1073741275;
      v13 = v26;
      goto LABEL_44;
    default:
      return -1073741584;
  }
  return v13;
}
