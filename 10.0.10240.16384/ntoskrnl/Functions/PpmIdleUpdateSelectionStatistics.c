// PpmIdleUpdateSelectionStatistics 
 
int __fastcall PpmIdleUpdateSelectionStatistics(__int64 a1, _QWORD *a2)
{
  if ( a1 )
    LODWORD(a1) = sub_54FE14();
  else
    ++*a2;
  return a1;
}
