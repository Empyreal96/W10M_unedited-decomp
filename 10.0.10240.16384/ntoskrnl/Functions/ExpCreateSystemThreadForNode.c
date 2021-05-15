// ExpCreateSystemThreadForNode 
 
int __fastcall ExpCreateSystemThreadForNode(int a1, int a2)
{
  _DWORD v5[4]; // [sp+20h] [bp-38h] BYREF
  int v6[10]; // [sp+30h] [bp-28h] BYREF

  KeQueryNodeActiveAffinity(*(unsigned __int16 *)(a2 + 266), v5, 0);
  KeSelectIdealProcessor(a2, (int)v5, (int *)(a2 + 1012));
  v6[0] = 24;
  v6[1] = 0;
  v6[2] = 0;
  v6[3] = 0;
  v6[4] = 0;
  v6[5] = 0;
  return PsCreateSystemThreadEx(a1, 0x1FFFFF, v6);
}
