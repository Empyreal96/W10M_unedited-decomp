// IoFreeWorkItem 
 
int __fastcall IoFreeWorkItem(_DWORD *a1)
{
  if ( *a1 )
    sub_524A5C();
  return ExFreePoolWithTag(a1, 0);
}
