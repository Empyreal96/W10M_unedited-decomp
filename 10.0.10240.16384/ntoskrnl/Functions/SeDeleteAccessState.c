// SeDeleteAccessState 
 
int __fastcall SeDeleteAccessState(int a1)
{
  SepDeleteAccessState(a1);
  return SeReleaseSubjectContext(a1 + 28);
}
