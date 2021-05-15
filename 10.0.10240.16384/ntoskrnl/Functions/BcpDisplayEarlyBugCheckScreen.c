// BcpDisplayEarlyBugCheckScreen 
 
int __fastcall BcpDisplayEarlyBugCheckScreen(unsigned int a1, _DWORD *a2, int a3)
{
  void **v6; // r6
  int v7; // r0
  int v8; // r1
  unsigned int v9; // r3
  __int16 v10; // r2
  int v11; // r4
  int v12; // r1
  int v13; // r0
  unsigned int v14; // r3
  __int16 v15; // r2

  v6 = BgConsoleGetInterface(a1);
  if ( v6 )
  {
    if ( ((int (__fastcall *)(int, int, int))*v6)(2, -1, -16777216) >= 0 )
    {
      ((void (*)(void))v6[1])();
      ((void (__fastcall *)(const __int16 *))v6[3])(L"Your PC needs to restart.\r\n");
      ((void (__fastcall *)(const __int16 *))v6[3])(L"Please hold down the power button.\r\n");
      ((void (__fastcall *)(const __int16 *))v6[3])(L"Error Code:");
      ((void (__fastcall *)(const __int16 *))v6[3])(L" ");
      **(_WORD **)(a3 + 12) = 48;
      v7 = 2;
      v8 = 28;
      *(_WORD *)(*(_DWORD *)(a3 + 12) + 2) = 120;
      do
      {
        v9 = (a1 >> v8) & 0xF;
        if ( v9 >= 0xA )
          v10 = (unsigned __int8)(v9 - 10) + 65;
        else
          v10 = v9 + 48;
        v8 -= 4;
        *(_WORD *)(*(_DWORD *)(a3 + 12) + 2 * v7++) = v10;
      }
      while ( v8 >= 0 );
      *(_WORD *)(*(_DWORD *)(a3 + 12) + 2 * v7) = 0;
      ((void (__fastcall *)(_DWORD))v6[3])(*(_DWORD *)(a3 + 12));
      ((void (__fastcall *)(const __int16 *))v6[3])(L"\r\n");
      ((void (__fastcall *)(const __int16 *))v6[3])(L"Parameters:");
      ((void (__fastcall *)(const __int16 *))v6[3])(L"\r\n");
      v11 = 4;
      do
      {
        v12 = 2;
        v13 = 28;
        **(_WORD **)(a3 + 20) = 48;
        *(_WORD *)(*(_DWORD *)(a3 + 20) + 2) = 120;
        do
        {
          v14 = (*a2 >> v13) & 0xF;
          if ( v14 >= 0xA )
            v15 = (unsigned __int8)(v14 - 10) + 65;
          else
            v15 = v14 + 48;
          v13 -= 4;
          *(_WORD *)(*(_DWORD *)(a3 + 20) + 2 * v12++) = v15;
        }
        while ( v13 >= 0 );
        *(_WORD *)(*(_DWORD *)(a3 + 20) + 2 * v12) = 0;
        ((void (__fastcall *)(_DWORD))v6[3])(*(_DWORD *)(a3 + 20));
        ((void (__fastcall *)(const __int16 *))v6[3])(L"\r\n");
        a3 += 8;
        --v11;
        ++a2;
      }
      while ( v11 );
    }
    BgConsoleDestroyInterface(v6);
  }
  return 0;
}
