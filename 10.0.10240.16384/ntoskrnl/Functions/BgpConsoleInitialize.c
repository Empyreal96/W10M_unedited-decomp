// BgpConsoleInitialize 
 
int __fastcall BgpConsoleInitialize(unsigned int a1, int a2, int a3)
{
  int v3; // r5
  unsigned __int16 v5; // r9
  int v6; // r10
  _DWORD *v7; // r0
  int v8; // r7
  int v10; // r4
  unsigned int v11; // r5
  unsigned int v12; // r0
  int v13; // r4
  int *v14; // r2
  unsigned int v15; // r1
  int *v16; // r3
  int v18[2]; // [sp+10h] [bp-38h] BYREF
  int v19; // [sp+18h] [bp-30h] BYREF
  int v20; // [sp+1Ch] [bp-2Ch]
  _DWORD v21[10]; // [sp+20h] [bp-28h] BYREF

  v3 = a3;
  v18[0] = a2;
  v5 = a1;
  v6 = 1;
  BgpFwAcquireLock(a1);
  dword_610350 |= v5;
  dword_610354 = a2;
  dword_610358 = v3;
  v7 = BgpGetResolution(&v19);
  dword_61035C = v19;
  dword_610360 = v20;
  unk_610364 = v21[0];
  v8 = v18[0];
  dword_610348 = 80;
  dword_61034C = 25;
  v19 = a3;
  v20 = v18[0];
  if ( (v5 & 2) != 0 )
    return sub_8DF2E8(v7);
  v21[2] = 1;
  v10 = BgpFoGetFontHandle(L"Segoe Mono Boot", v21);
  if ( v10 >= 0 )
  {
    v10 = BgpConsoleSetPointSize(dword_61034C, dword_610348, dword_610360, dword_61035C, (int)&v19, (int)v18);
    if ( v10 >= 0 )
    {
      dword_610368 = v21[1];
      dword_610370 = v18[0];
      dword_610374 = v18[1];
      if ( (v5 & 4) == 0 )
        v6 = 3;
      dword_61036C = BgpDisplayCharacterGetContext(&v19, &dword_610370, v6);
      if ( dword_61036C )
      {
        v11 = dword_610348;
        v12 = 0;
        dword_61037C = (unsigned int)(dword_61035C - dword_610370 * dword_610348) >> 1;
        v13 = dword_61034C;
        dword_610380 = (unsigned int)(dword_610360 - dword_610374 * dword_61034C) >> 1;
        dword_61038C = 0;
        dword_610384 = 0;
        dword_610388 = 0;
        if ( dword_610348 )
        {
          v14 = &dword_610348;
          do
          {
            v15 = 0;
            if ( v13 )
            {
              v16 = v14;
              do
              {
                *((_WORD *)v16 + 40) = 32;
                v16[18] = v8;
                v16[19] = a3;
                v13 = dword_61034C;
                ++v15;
                v16 += 3;
              }
              while ( v15 < dword_61034C );
              v11 = dword_610348;
            }
            ++v12;
            v14 += 75;
          }
          while ( v12 < v11 );
        }
        if ( (v5 & 1) != 0 )
          BgpConsoleClearScreenEx(v12);
        v10 = 0;
      }
      else
      {
        v10 = -1073741823;
      }
    }
  }
  BgpFwReleaseLock();
  return v10;
}
