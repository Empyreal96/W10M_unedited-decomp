// CmpFreePostBlock 
 
unsigned int __fastcall CmpFreePostBlock(_DWORD *a1)
{
  if ( a1[6] )
    return sub_7E8228();
  if ( (a1[7] & 0x10000) != 0 )
    ExFreePoolWithTag(a1[8]);
  return ExFreePoolWithTag((unsigned int)a1);
}
