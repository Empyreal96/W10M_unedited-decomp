// KiQueryProcessorNode 
 
int __fastcall KiQueryProcessorNode(unsigned int a1, int a2, _WORD *a3)
{
  int v5; // r7
  int v6; // r0
  int v7; // r4

  if ( a1 < KeNumberProcessors_0 )
    return sub_50B5A0();
  v5 = (unsigned __int16)*a3;
  if ( !KiNumaQueryProcessorNode )
  {
    if ( a1 >= KiMaximumGroupSize )
    {
      v7 = -1073741275;
      goto LABEL_7;
    }
    *a3 = 0;
    goto LABEL_18;
  }
  v6 = KiNumaQueryProcessorNode();
  v7 = v6;
  if ( v6 )
  {
    if ( v6 != -1073741275 )
      goto LABEL_7;
    if ( v5 == 0xFFFF || KiIsNodeFull(*(&KeNodeBlock + v5)) )
      return v7;
    *a3 = v5;
LABEL_18:
    v7 = 0;
    goto LABEL_7;
  }
  if ( (unsigned __int16)*a3 != 0xFFFF )
    goto LABEL_8;
  v7 = KiFindFirstAvailableNode(a3);
LABEL_7:
  if ( !v7 )
  {
LABEL_8:
    if ( (*((_BYTE *)*(&KeNodeBlock + (unsigned __int16)*a3) + 289) & 2) == 0 )
      v7 = -1073741275;
  }
  return v7;
}
