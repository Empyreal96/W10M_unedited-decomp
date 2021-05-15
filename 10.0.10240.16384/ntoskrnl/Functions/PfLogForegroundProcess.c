// PfLogForegroundProcess 
 
int __fastcall PfLogForegroundProcess(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // [sp+0h] [bp-18h] BYREF
  int v6; // [sp+4h] [bp-14h]
  unsigned int v7; // [sp+8h] [bp-10h] BYREF
  unsigned int v8; // [sp+Ch] [bp-Ch]

  v6 = a2;
  v7 = a3;
  v8 = a4;
  v5 = a1 - 492;
  v6 = *(_DWORD *)(a1 - 84);
  KeQueryTickCount((int *)&v7);
  return PfLogEvent(
           7,
           ((__int64)(((v7 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                    + ((v8 * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
         + dword_63728C,
           (int)&v5,
           8u);
}
