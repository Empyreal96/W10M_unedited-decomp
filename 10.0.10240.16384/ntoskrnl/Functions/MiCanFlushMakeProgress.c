// MiCanFlushMakeProgress 
 
int __fastcall MiCanFlushMakeProgress(_DWORD *a1, int a2)
{
  unsigned int v3; // r1
  int v4; // r2
  int v5; // r4
  __int16 v6; // r3

  if ( !a2 && a1[992] != a1[1030] )
    return 1;
  v3 = a1[899];
  __dmb(0xBu);
  if ( v3 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = a1[v4 + 900];
      if ( *(_DWORD *)(v5 + 12) )
      {
        v6 = *(_WORD *)(v5 + 96);
        if ( (v6 & 0x40) == 0 )
        {
          if ( (v6 & 0x10) == 0 )
            break;
          a1 = *(_DWORD **)(v5 + 128);
          if ( a1[5 * (v6 & 0xF) + 480] )
            break;
        }
      }
      if ( ++v4 >= v3 )
        return 0;
    }
    return 1;
  }
  return 0;
}
