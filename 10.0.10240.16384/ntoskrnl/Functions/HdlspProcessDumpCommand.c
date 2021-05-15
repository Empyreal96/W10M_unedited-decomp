// HdlspProcessDumpCommand 
 
int __fastcall HdlspProcessDumpCommand(__int64 a1)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r2
  bool v4; // zf
  _DWORD *v5; // r0
  unsigned int v6; // r9
  int i; // r10
  int v8; // r2
  int v9; // r3
  int v10; // r5
  int v11; // r1
  unsigned __int16 *v12; // r4
  int v13; // r3
  int v14; // r1
  unsigned int *v15; // r4
  unsigned int v16; // r2
  int v17; // r1
  unsigned int v18; // r2
  const char *v19; // r0
  char v21[4]; // [sp+10h] [bp-50h] BYREF
  int v22; // [sp+14h] [bp-4Ch]
  int v23; // [sp+18h] [bp-48h]
  unsigned __int16 v24[2]; // [sp+20h] [bp-40h] BYREF
  int v25; // [sp+24h] [bp-3Ch]
  unsigned __int16 v26[4]; // [sp+28h] [bp-38h] BYREF
  _WORD var30[26]; // [sp+30h] [bp-30h] BYREF
  int vars4; // [sp+64h] [bp+4h]

  v23 = a1;
  v1 = HeadlessGlobals;
  if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) != 0 )
  {
    v2 = 255;
  }
  else
  {
    LODWORD(a1) = KfRaiseIrql(2);
    v2 = a1;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      LODWORD(a1) = KiAcquireSpinLockInstrumented(v1);
    }
    else
    {
      do
        v3 = __ldrex((unsigned int *)v1);
      while ( __strex(1u, (unsigned int *)v1) );
      __dmb(0xBu);
      if ( v3 )
        LODWORD(a1) = KxWaitForSpinLockAndAcquire((unsigned int *)v1);
    }
    v1 = HeadlessGlobals;
  }
  if ( *(unsigned __int16 *)(v1 + 62) != 0xFFFF )
  {
    v6 = 0;
    *(_DWORD *)(v1 + 24) &= 0xFFFFFFFB;
    v24[0] = 0;
    v24[1] = 80;
    v25 = *(_DWORD *)(v1 + 12);
    for ( i = *(unsigned __int16 *)(v1 + 62); ; i = (unsigned __int8)(i + 1) )
    {
      v8 = 7 * i;
      v9 = *(_DWORD *)(v1 + 8) + 56 * i;
      v22 = v9;
      if ( v2 != 255 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented((_DWORD *)v1, vars4);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v1 = 0;
        }
        KfLowerIrql(v2);
        v1 = HeadlessGlobals;
      }
      v10 = v22;
      RtlTimeToTimeFields(v22 + 8, var30, v8, v9);
      sprintf_s(*(_DWORD *)(v1 + 12), 80, (int)"%02d:%02d:%02d.%03d : ", var30[3], var30[4], var30[5], var30[6]);
      HdlspPutString(*(_DWORD *)(HeadlessGlobals + 12), v11);
      v12 = *(unsigned __int16 **)(v10 + 48);
      if ( wcslen(v12) >= 0x4F )
        v12[79] = 0;
      RtlInitUnicodeString((unsigned int)v26, *(unsigned __int16 **)(v10 + 48));
      RtlUnicodeStringToAnsiString(v24, v26, 0, v13);
      v15 = (unsigned int *)HeadlessGlobals;
      if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) != 0 )
      {
        v2 = 255;
      }
      else
      {
        v2 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)v15);
        }
        else
        {
          v14 = 1;
          do
            v16 = __ldrex(v15);
          while ( __strex(1u, v15) );
          __dmb(0xBu);
          if ( v16 )
            KxWaitForSpinLockAndAcquire(v15);
        }
        v15 = (unsigned int *)HeadlessGlobals;
      }
      if ( (v15[6] & 4) != 0 )
        break;
      HdlspPutString(v15[3], v14);
      LODWORD(a1) = HdlspPutString("\r\n", v17);
      v1 = HeadlessGlobals;
      ++v6;
      if ( i == *(unsigned __int16 *)(HeadlessGlobals + 60) )
      {
        if ( v2 == 255 )
          return a1;
        v4 = (dword_682604 & 0x10000) == 0;
        goto LABEL_12;
      }
      if ( v23 && v6 > 0x14 )
      {
        if ( v2 != 255 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented((_DWORD *)HeadlessGlobals, vars4);
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v1 = 0;
          }
          a1 = KfLowerIrql(v2);
        }
        HdlspPutMore(v21, HIDWORD(a1));
        v1 = HeadlessGlobals;
        if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) != 0 )
        {
          v2 = 255;
        }
        else
        {
          v2 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v1);
          }
          else
          {
            v14 = 1;
            do
              v18 = __ldrex((unsigned int *)v1);
            while ( __strex(1u, (unsigned int *)v1) );
            __dmb(0xBu);
            if ( v18 )
              KxWaitForSpinLockAndAcquire((unsigned int *)v1);
          }
          v1 = HeadlessGlobals;
        }
        if ( v21[0] )
        {
          v19 = "\r\n";
          goto LABEL_59;
        }
        if ( (*(_DWORD *)(v1 + 24) & 4) != 0 )
        {
          v19 = "New log entries have been added while waiting, command aborted.\r\n";
          goto LABEL_59;
        }
        v6 = 0;
      }
    }
    v19 = "New log entries have been added during dump, command aborted.\r\n";
LABEL_59:
    LODWORD(a1) = HdlspPutString(v19, v14);
    if ( v2 == 255 )
      return a1;
    v5 = (_DWORD *)HeadlessGlobals;
    if ( (dword_682604 & 0x10000) == 0 )
    {
      __dmb(0xBu);
      *v5 = 0;
      goto LABEL_63;
    }
    goto LABEL_61;
  }
  if ( v2 != 255 )
  {
    v4 = (dword_682604 & 0x10000) == 0;
LABEL_12:
    if ( v4 )
    {
      __dmb(0xBu);
      *(_DWORD *)v1 = 0;
LABEL_63:
      LODWORD(a1) = KfLowerIrql(v2);
      return a1;
    }
    v5 = (_DWORD *)v1;
LABEL_61:
    KiReleaseSpinLockInstrumented(v5, vars4);
    goto LABEL_63;
  }
  return a1;
}
