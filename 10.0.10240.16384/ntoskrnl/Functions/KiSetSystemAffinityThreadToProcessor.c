// KiSetSystemAffinityThreadToProcessor 
 
__int64 __fastcall KiSetSystemAffinityThreadToProcessor(char a1, int a2, int a3, int a4)
{
  __int64 v5; // [sp+0h] [bp-10h] BYREF
  int v6; // [sp+8h] [bp-8h]
  int v7; // [sp+Ch] [bp-4h]

  v7 = a4;
  v6 = 0;
  v5 = (unsigned int)(1 << a1);
  KeSetSystemGroupAffinityThread(&v5, a2);
  return v5;
}
