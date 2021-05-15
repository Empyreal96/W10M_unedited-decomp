// PpmConvertTimeTo 
 
int __fastcall PpmConvertTimeTo(int a1, int a2)
{
  return PpmConvertTime(a1, a2, PopQpcFrequency, MEMORY[0x682514]);
}
