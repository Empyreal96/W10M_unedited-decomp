// BgpConsoleDisplayCharacter 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BgpConsoleDisplayCharacter(unsigned int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  int *v9; // r5
  int v11; // r4
  int v13; // [sp+10h] [bp-30h]
  char v15[4]; // [sp+1Ch] [bp-24h] BYREF
  char v16[32]; // [sp+20h] [bp-20h] BYREF

  v5 = a3;
  BgpFwAcquireLock(a1);
  if ( (dword_610350 & 0x10000) != 0 )
  {
    AnFwFadeCompletion();
    dword_610350 &= 0xFFFEFFFF;
  }
  v9 = &dword_610390[75 * a2 + 3 * v5];
  if ( *((unsigned __int16 *)v9 + 4) == a1 && *v9 == a4 && v9[1] == a5 )
  {
    v11 = 0;
  }
  else
  {
    v11 = BgpDisplayCharacterEx(
            a1,
            (int *)dword_61036C,
            dword_61037C + dword_610370 * a2,
            dword_610380 + dword_610374 * a3,
            a5,
            a4,
            (int)v16,
            (int)v15,
            v13,
            0);
    if ( v11 >= 0 )
    {
      *((_WORD *)v9 + 4) = a1;
      *(_QWORD *)v9 = *(_QWORD *)&a4;
    }
  }
  BgpFwReleaseLock();
  return v11;
}
