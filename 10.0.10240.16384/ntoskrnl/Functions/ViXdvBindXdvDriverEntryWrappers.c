// ViXdvBindXdvDriverEntryWrappers 
 
int __fastcall ViXdvBindXdvDriverEntryWrappers(int (__fastcall *a1)(_DWORD, int, int, _DWORD), int a2, int a3)
{
  int v3; // r4
  _DWORD *v4; // r0
  void **v5; // r2
  int v6; // r1
  int v7; // lr
  void ***i; // r3
  void **v9; // r6

  ViXdvEPThunksNoXdvEntry = 0;
  ViXdvEPBound = 0;
  if ( !a1 )
    return 0;
  v3 = 0;
  v4 = (_DWORD *)a1(a1, a2, a3, 0);
  if ( v4 )
  {
    if ( *v4 == 5 )
    {
      v5 = 0;
      v3 = 1;
      while ( (unsigned int)v5 < v4[1] )
      {
        if ( v4[(_DWORD)v5 + 2] )
        {
          v6 = 0;
          v7 = 0;
          for ( i = &VfXdvIoCallbackThunks; ; i = &(&VfXdvIoCallbackThunks)[2 * v6] )
          {
            v9 = i[1];
            if ( v9 == (void **)102 || v7 == 1 )
              break;
            if ( v9 == v5 )
            {
              v7 = 1;
              if ( *i )
              {
                **i = (void *)v4[(_DWORD)v5 + 2];
                ++ViXdvEPBound;
              }
            }
            ++v6;
          }
        }
        else
        {
          ++ViXdvEPThunksNoXdvEntry;
        }
        v5 = (void **)((char *)v5 + 1);
      }
    }
    else
    {
      VfUtilDbgPrint((int)"XDV entry point version mismatch: kernel version %d   driver version %d\n");
    }
  }
  return v3;
}
