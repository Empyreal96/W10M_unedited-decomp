// KiFindFirstAvailableNode 
 
int __fastcall KiFindFirstAvailableNode(_WORD *a1)
{
  if ( !KeNumberNodes )
    return -1073741275;
  if ( (*((_BYTE *)KeNodeBlock + 289) & 2) == 0 || KiIsNodeFull(KeNodeBlock) )
    return sub_50B5F4();
  *a1 = 0;
  return 0;
}
