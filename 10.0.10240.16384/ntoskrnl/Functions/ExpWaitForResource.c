// ExpWaitForResource 
 
int __fastcall ExpWaitForResource(int a1, int a2)
{
  unsigned int v2; // lr
  unsigned int v4; // r3
  int v5; // r5
  unsigned int v6; // r6
  int v7; // r1
  int v8; // r2
  int result; // r0
  int v10; // r2
  unsigned int v11; // r2
  int v12; // [sp+8h] [bp-48h]
  int v13; // [sp+Ch] [bp-44h]
  int v15; // [sp+28h] [bp-28h] BYREF
  int v16; // [sp+2Ch] [bp-24h]
  int anonymous2; // [sp+58h] [bp+8h]
  int anonymous3; // [sp+5Ch] [bp+Ch]

  v2 = a2;
  anonymous3 = a2;
  anonymous2 = a1;
  v4 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v4 & 0xFFFFF000) + 0x1428);
  v13 = 0;
  if ( *(_DWORD *)(a1 + 20) == a2 )
    v5 = 66084;
  else
    v5 = 66116;
  v12 = 0;
  ++*(_DWORD *)(a1 + 36);
  v15 = -5000000;
  v16 = -1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = 0;
  v8 = (*(_DWORD *)(v6 + 0x3C0) >> 9) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(v6 + 0x150) + 192) & 0x100000) != 0 )
    v8 = 0;
  if ( v8 < 2 && v6 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(v6 + 1000) )
    v8 = 2;
  if ( v8 > 1 && (*(_WORD *)(a1 + 14) & 4) == 0 )
    v7 = 4;
  if ( *(char *)(v6 + 123) > (int)*(unsigned __int8 *)(a1 + 15) )
    v7 |= 0xFF00u;
  if ( v7 )
  {
    ExpApplyPriorityBoost(a1, v7, v6);
    v2 = a2;
  }
  while ( 1 )
  {
    result = KeWaitForSingleObject(v2, 27, 0, 0, &v15);
    if ( result != 258 )
      break;
    v10 = ++v13;
    if ( (dword_682604 & 0x20000) != 0 )
      PerfLogExecutiveResourceWait(v5, a1, v10);
    v11 = ++v12;
    v15 = ExpTimeout;
    v16 = dword_61A0DC;
    if ( ExResourceTimeoutCount )
    {
      if ( v11 > ExResourceTimeoutCount )
      {
        DbgPrintEx(0, 0, (int)"Possible deadlock. Use !locks %p to determine the resource owner\n", a1);
        __debugbreak();
      }
    }
    ExpApplyPriorityBoost(a1, 65280, v6);
    v2 = a2;
  }
  return result;
}
