// PfpEventHandleFullBuffer 
 
int __fastcall PfpEventHandleFullBuffer(_DWORD *a1)
{
  int result; // r0

  result = PfTFullEventListAdd(a1);
  if ( !dword_643B50 && (unsigned __int16)word_643A54 >= (unsigned int)(2 * (KeNumberProcessors_0 + 2)) >> 1 )
    result = KeSetEvent((int)algn_643B4C, 0, 0);
  return result;
}
