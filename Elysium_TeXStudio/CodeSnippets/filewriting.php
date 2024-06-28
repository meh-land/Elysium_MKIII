use Illuminate\Support\Facades\Storage;
 
Storage::disk('local')->put('example.txt', 'Contents');