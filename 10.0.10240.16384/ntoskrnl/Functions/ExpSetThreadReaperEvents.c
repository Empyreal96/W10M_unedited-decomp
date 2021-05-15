// ExpSetThreadReaperEvents 
 
int ExpSetThreadReaperEvents()
{
  unsigned int v0; // r2
  unsigned int v1; // r4
  int v2; // r2
  int v3; // r3
  int result; // r0

  v0 = 0;
  if ( KeNumberNodes )
  {
    v1 = 0;
    do
    {
      v2 = (int)*(&KeNodeBlock + v0);
      if ( (_UNKNOWN *)v2 != (_UNKNOWN *)((char *)&KiNodeInit + 384 * v1) && v2 )
      {
        v3 = *(_DWORD *)(v2 + 1016);
        __dmb(0xBu);
        if ( (v3 & 1) != 0 )
          result = KeSetEvent(v2 + 920, 0, 0);
      }
      v0 = (unsigned __int16)(v1 + 1);
      v1 = v0;
    }
    while ( v0 < (unsigned __int16)KeNumberNodes );
  }
  return result;
}
