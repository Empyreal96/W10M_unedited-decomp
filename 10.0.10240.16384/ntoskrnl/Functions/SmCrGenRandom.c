// SmCrGenRandom 
 
int __fastcall SmCrGenRandom(int a1, int a2)
{
  return BCryptGenRandom(a1, a1, a2);
}
