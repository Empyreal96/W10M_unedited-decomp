// MiFinalizeDriverImage 
 
int __fastcall MiFinalizeDriverImage(int a1)
{
  VfDriverLoadImage(a1, 0, 0, 0);
  return KseDriverLoadImage(a1);
}
