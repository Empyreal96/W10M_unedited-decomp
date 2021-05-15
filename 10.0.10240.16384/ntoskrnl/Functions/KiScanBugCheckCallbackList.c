// KiScanBugCheckCallbackList 
 
int __fastcall KiScanBugCheckCallbackList(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r3
  int *v5; // r9
  unsigned int v6; // r8
  unsigned int i; // r6
  int result; // r0
  int (*v9)(void); // r6

  v3 = KeBugCheckCallbackListHead;
  if ( KeBugCheckCallbackListHead )
  {
    v4 = dword_624F84;
    if ( dword_624F84 )
    {
      v5 = &KeBugCheckCallbackListHead;
      while ( (int *)v3 != &KeBugCheckCallbackListHead && (v3 & 3) == 0 )
      {
        v6 = v3;
        for ( i = 0; i < 0x20; ++i )
        {
          result = MiIsAddressValid(v6, 0, a3, v4);
          if ( !result )
            return result;
          ++v6;
        }
        if ( *(int **)(v3 + 4) != v5 )
          break;
        result = *(_DWORD *)(v3 + 12);
        v9 = *(int (**)(void))(v3 + 8);
        a3 = (int)v9 + *(_DWORD *)(v3 + 20) + result + *(_DWORD *)(v3 + 16);
        v4 = *(unsigned __int8 *)(v3 + 28);
        if ( v4 == 1 )
        {
          v4 = *(_DWORD *)(v3 + 24);
          if ( v4 == a3 )
          {
            *(_BYTE *)(v3 + 28) = 2;
            result = v9();
            *(_BYTE *)(v3 + 28) = 3;
          }
        }
        v5 = (int *)v3;
        v3 = *(_DWORD *)v3;
      }
    }
  }
  return result;
}
