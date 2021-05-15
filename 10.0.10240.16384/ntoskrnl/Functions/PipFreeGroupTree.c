// PipFreeGroupTree 
 
unsigned int __fastcall PipFreeGroupTree(_DWORD *a1)
{
  if ( *a1 )
    PipFreeGroupTree();
  if ( a1[2] )
    PipFreeGroupTree();
  if ( a1[1] )
    PipFreeGroupTree();
  return ExFreePoolWithTag((unsigned int)a1);
}
