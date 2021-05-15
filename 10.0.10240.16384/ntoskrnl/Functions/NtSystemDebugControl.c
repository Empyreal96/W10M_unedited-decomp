// NtSystemDebugControl 
 
int __fastcall NtSystemDebugControl(int a1, unsigned int a2, int a3, bool *a4, unsigned int a5, _DWORD *a6)
{
  bool *v6; // r5
  int v10; // r4
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r3
  unsigned int v14; // r6
  _DWORD *v15; // r5
  int *v16; // r2
  int v17; // r0
  int *v18; // r1
  int v19; // r3
  char *v20; // r3
  int v21; // r3
  int *v22; // r3
  int v23; // r3
  int v24; // r10
  _BYTE *v25; // r8
  int v26; // r0
  int v29; // [sp+14h] [bp-5Ch]
  unsigned int v30; // [sp+18h] [bp-58h] BYREF
  int v31[2]; // [sp+1Ch] [bp-54h] BYREF
  int v32; // [sp+24h] [bp-4Ch] BYREF
  int v33; // [sp+28h] [bp-48h] BYREF
  int v34; // [sp+2Ch] [bp-44h]
  int v35; // [sp+30h] [bp-40h] BYREF
  _DWORD _34[21]; // [sp+34h] [bp-3Ch] BYREF

  v6 = a4;
  _34[20] = a4;
  _34[19] = a3;
  _34[18] = a2;
  v31[0] = a1;
  _34[17] = a1;
  v30 = 0;
  v35 = 0;
  memset(_34, 0, 32);
  v32 = 0;
  v33 = 0;
  if ( KdPitchDebugger && !KdLocalDebugEnabled && a1 != 29 && a1 != 37 )
    return -1073740972;
  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v29 = v11;
  v12 = SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v11, (int)&SeDebugPrivilege);
  if ( !v12 )
    return -1073741790;
  v10 = 0;
  if ( v11 )
  {
    if ( a3 )
    {
      if ( (a2 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v12);
      v13 = MmUserProbeAddress;
      if ( a2 + a3 > MmUserProbeAddress || a2 + a3 < a2 )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v13 = MmUserProbeAddress;
      }
    }
    else
    {
      v13 = MmUserProbeAddress;
    }
    v14 = a5;
    if ( a5 )
    {
      ProbeForWrite(v6, a5, 4);
      v13 = MmUserProbeAddress;
    }
    v15 = a6;
    if ( a6 )
    {
      v16 = a6;
      if ( (unsigned int)a6 >= v13 )
        v16 = (int *)v13;
      v34 = *v16;
      *v16 = v34;
    }
  }
  else
  {
    v15 = a6;
    v14 = a5;
  }
  switch ( v31[0] )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
      return -1073741822;
    case 6:
      if ( KdDebuggerEnabled == 1 )
        DbgBreakPointWithStatus();
      v10 = -1073741823;
      goto LABEL_80;
    case 0x15:
      v17 = KdEnableDebugger();
      goto LABEL_29;
    case 0x16:
      v17 = KdDisableDebugger();
      goto LABEL_29;
    case 0x17:
      if ( v14 != 1 )
        goto LABEL_32;
      *a4 = KdAutoEnableOnEvent;
      goto LABEL_80;
    case 0x18:
      if ( a3 != 1 )
        goto LABEL_32;
      KdAutoEnableOnEvent = *(_BYTE *)a2 != 0;
      goto LABEL_80;
    case 0x19:
      if ( v14 != 4 )
        goto LABEL_32;
      *(_DWORD *)a4 = KdPrintBufferSize;
      goto LABEL_80;
    case 0x1A:
      if ( a3 != 4 )
        goto LABEL_32;
      v31[1] = 0;
      v17 = KdSetDbgPrintBufferSize(*(_DWORD *)a2);
LABEL_29:
      v10 = v17;
      goto LABEL_80;
    case 0x1B:
      if ( v14 != 1 )
        goto LABEL_32;
      *a4 = KdIgnoreUmExceptions == 0;
      goto LABEL_80;
    case 0x1C:
      if ( a3 != 1 )
        goto LABEL_32;
      KdIgnoreUmExceptions = *(_BYTE *)a2 == 0;
      goto LABEL_80;
    case 0x1D:
      if ( a3 != 36 || v14 < 0x20000 )
        goto LABEL_32;
      memmove((int)&v35, a2, 0x24u);
      if ( _34[5]
        || !_34[6]
        || (v35 & 0xFFFFFFFE) != 0
        || (RtlULongLongToULong(4 * _34[6], _34[6] >> 30, v31) & 0xC0000000) == -1073741824 )
      {
        return -1073741811;
      }
      v24 = 0x100000;
      if ( v14 <= 0x100000 )
        v24 = v14;
      v25 = (_BYTE *)ExAllocatePoolWithTag(512, v24, 1884181323);
      if ( v25 )
      {
        v10 = ExLockUserBuffer(_34[7], v31[0], v29, 0, &v32, &v33);
        if ( v10 < 0 )
        {
          ExFreePoolWithTag((unsigned int)v25);
        }
        else
        {
          memset(v25, 0, v24);
          _34[7] = v32;
          v26 = DbgkCaptureLiveDump(&v35, v25, v24, &v30);
          v10 = v26;
          if ( v26 >= 0 )
          {
            if ( v30 <= v14 )
              memmove((int)a4, (int)v25, v30);
            else
              v10 = -1073741823;
          }
          ExFreePoolWithTag((unsigned int)v25);
          ExUnlockUserBuffer(v33);
        }
      }
      else
      {
        v10 = -1073741801;
      }
      goto LABEL_80;
    case 0x1E:
      if ( v14 != 1 )
        goto LABEL_32;
      *a4 = KdBlockEnable;
      goto LABEL_80;
    case 0x1F:
      if ( a3 != 1 )
        goto LABEL_32;
      KdBlockEnable = *(_BYTE *)a2;
      goto LABEL_80;
    case 0x20:
      __dmb(0xBu);
      KdUmBreakMarker = -618808389;
      goto LABEL_49;
    case 0x21:
      if ( v14 != 4 )
        goto LABEL_32;
      v18 = &KdUmBreakPid;
      v19 = KdUmBreakPid;
      __dmb(0xBu);
      *(_DWORD *)a4 = v19;
      v20 = &KdResetUmBreakPid;
      goto LABEL_52;
    case 0x22:
      __dmb(0xBu);
      v22 = &KdUmBreakPid;
      goto LABEL_55;
    case 0x23:
      if ( v14 == 4 )
      {
        v18 = &KdUmAttachPid;
        v23 = KdUmAttachPid;
        __dmb(0xBu);
        *(_DWORD *)a4 = v23;
        v20 = &KdResetUmAttachPid;
LABEL_52:
        v21 = (unsigned __int8)*v20;
        __dmb(0xBu);
        if ( v21 )
        {
          __dmb(0xBu);
          *v18 = 0;
        }
LABEL_49:
        v10 = 0;
LABEL_80:
        if ( v15 )
          *v15 = v30;
      }
      else
      {
LABEL_32:
        v10 = -1073741820;
      }
      break;
    case 0x24:
      __dmb(0xBu);
      v22 = &KdUmAttachPid;
LABEL_55:
      *v22 = 0;
      goto LABEL_49;
    case 0x25:
      v10 = -1073741822;
      goto LABEL_80;
    default:
      v10 = -1073741821;
      goto LABEL_80;
  }
  return v10;
}
