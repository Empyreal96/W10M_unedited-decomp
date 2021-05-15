// KiAbProcessThreadPriorityModification 
 
int __fastcall KiAbProcessThreadPriorityModification(int result, int a2, int a3)
{
  unsigned int v3; // r4
  _DWORD *v4; // r2
  _DWORD *v5; // r1
  unsigned __int16 *v6; // r2
  unsigned int v7; // r1

  a2 = (char)a2;
  if ( KiAbEnabled )
  {
    v3 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    if ( a3 )
    {
      if ( a3 != 1 || a2 <= *(char *)(result + 123) || !*(_BYTE *)(result + 485) || *(_DWORD *)(result + 776) != 1 )
        return result;
      v4 = (_DWORD *)(v3 + 17412);
      v5 = (_DWORD *)(result + 776);
    }
    else
    {
      if ( a2 >= *(char *)(result + 347) || !*(_BYTE *)(result + 811) || *(_DWORD *)(result + 780) != 1 )
        return result;
      v5 = (_DWORD *)(result + 780);
      v4 = (_DWORD *)(v3 + 17408);
    }
    if ( v4 )
    {
      *v5 = *v4;
      *v4 = v5;
      __dmb(0xBu);
      v6 = (unsigned __int16 *)(result + 808);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 + 1, v6) );
      __dmb(0xBu);
      result = KiAbQueueAutoBoostDpc(v3);
    }
  }
  return result;
}
