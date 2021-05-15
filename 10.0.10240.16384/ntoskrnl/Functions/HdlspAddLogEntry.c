// HdlspAddLogEntry 
 
unsigned int __fastcall HdlspAddLogEntry(unsigned __int16 *a1)
{
  unsigned int v2; // r8
  unsigned int v3; // r0
  unsigned int v4; // r4
  unsigned int result; // r0
  int v6; // r0
  int v7; // r5
  int v8; // r4
  int v9; // r6
  unsigned int v10; // r2
  int v11; // r9
  int v12; // r3
  int v13; // r2
  char *v14; // r10
  int v15; // r3
  _DWORD *v16; // r0
  int v17; // [sp+0h] [bp-58h]
  char var50[84]; // [sp+8h] [bp-50h] BYREF
  int vars4; // [sp+5Ch] [bp+4h]

  v2 = 0;
  v3 = wcslen(a1);
  v4 = v3 + 1;
  result = KeGetCurrentIrql(v3);
  if ( result < 2 )
  {
    if ( ZwQuerySystemInformation() < 0 )
      memset(var50, 0, 48);
    v6 = ExAllocatePoolWithTag(512, 2 * v4, 1936483400);
    v7 = v6;
    if ( v6 )
      memmove(v6, (int)a1, 2 * v4);
    v8 = HeadlessGlobals;
    if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) != 0 )
    {
      v9 = 255;
    }
    else
    {
      v9 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v8);
      }
      else
      {
        do
          v10 = __ldrex((unsigned int *)v8);
        while ( __strex(1u, (unsigned int *)v8) );
        __dmb(0xBu);
        if ( v10 )
          KxWaitForSpinLockAndAcquire((unsigned int *)v8);
      }
      v8 = HeadlessGlobals;
    }
    v11 = *(unsigned __int16 *)(v8 + 62);
    *(_DWORD *)(v8 + 24) |= 4u;
    v12 = (unsigned __int16)(*(_WORD *)(v8 + 60) + 1) - ((int)(unsigned __int16)(*(_WORD *)(v8 + 60) + 1) >> 8 << 8);
    v13 = (unsigned __int16)v12;
    v17 = (unsigned __int16)v12;
    *(_WORD *)(v8 + 60) = v12;
    if ( (unsigned __int16)v12 == v11 )
    {
      v14 = *(char **)(*(_DWORD *)(v8 + 8) + 56 * v11 + 48);
      if ( wcscmp(v14, (char *)L"Entry could not be recorded due to lack of memory.\n") )
        v2 = (unsigned int)v14;
      v13 = v17;
      *(_WORD *)(v8 + 62) = v11 + 1 - ((int)(unsigned __int16)(v11 + 1) >> 8 << 8);
    }
    else if ( v11 == 0xFFFF )
    {
      *(_WORD *)(v8 + 62) = 0;
    }
    result = memmove(*(_DWORD *)(v8 + 8) + 56 * v13, (int)var50, 0x30u);
    v15 = *(_DWORD *)(v8 + 8) + 56 * *(unsigned __int16 *)(v8 + 60);
    if ( v7 )
      *(_DWORD *)(v15 + 48) = v7;
    else
      *(_DWORD *)(v15 + 48) = L"Entry could not be recorded due to lack of memory.\n";
    if ( v9 != 255 )
    {
      v16 = (_DWORD *)HeadlessGlobals;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)HeadlessGlobals, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v16 = 0;
      }
      result = KfLowerIrql(v9);
    }
    if ( v2 )
      result = ExFreePoolWithTag(v2);
  }
  return result;
}
