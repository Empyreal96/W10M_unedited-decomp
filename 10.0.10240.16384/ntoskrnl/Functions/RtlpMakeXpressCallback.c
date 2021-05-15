// RtlpMakeXpressCallback 
 
unsigned int __fastcall RtlpMakeXpressCallback(int a1, unsigned int a2, int a3)
{
  (*(void (__fastcall **)(_DWORD))a1)(*(_DWORD *)(a1 + 4));
  if ( a2 >= *(_DWORD *)(a1 + 8) + a3 )
    a2 = *(_DWORD *)(a1 + 8) + a3;
  return a2;
}
